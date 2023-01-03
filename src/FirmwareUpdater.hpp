#ifndef FIRMWARE_UPDATER_H
#define FIRMWARE_UPDATER_H

#define TINY_GSM_MODEM_SIM800
#include <Arduino.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
// #include <ArduinoHttpClient.h>
#include <TinyGsmClient.h>
#include <WiFi.h>

// This enumeration represents the possible network types
enum NetworkType {
  TINYGSM,
  WIFI
}; 

// This enumeration represents the possible connection types
enum ConnectionType {
  HTTP,
  HTTPS
};

class FirmwareUpdater {
  public:
    // Constructor
    FirmwareUpdater(NetworkType networkType, ConnectionType connectionType) :
      _networkType(networkType), _connectionType(connectionType)
    {
      _modemSerial = Serial1;
    }

    // Destructor
    ~FirmwareUpdater() {
      if (_client) {
        delete _client;
      }
    }

    // Initialize the network connection
    void begin(PGM_P apn, PGM_P user, PGM_P pass) {
      // Initialize the TinyGSM modem and create a GSM client
      if (_networkType == TINYGSM) {
        _modemSerial.begin(115200, SERIAL_8N1, 16, 17);
        _modem.init("");
        _modem.gprsConnect(apn, user, pass);
        _client = new TinyGsmClient(_modem);
      }

      // Initialize the WiFi connection
      if (_networkType == WIFI) {
        WiFi.begin();
        _client = new WiFiClient();
      }
    }

    // Perform the update
    void update(PGM_P server, PGM_P filePath) {
      // Use the appropriate HTTP client library based on the connection type
      HttpClient *http;
      if (_connectionType == HTTP) {
        http = new HttpClient(*_client, server);
      }
      if (_connectionType == HTTPS) {
        http = new HTTPClient(*_client, server);
      }

      // Perform an HTTP GET request to retrieve the update file
      log_d("Connecting to update server...");
      String url = String(server) + "/" + String(filePath);
      int ret = http->get(url.c_str());

      // Check the response status
    // Continue the update
    if (ret == HTTP_UPDATE_FAILED) {
      log_d("Update failed (error %d): %s", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
    } else if (ret == HTTP_UPDATE_NO_UPDATES) {
      log_d("No updates available");
    } else if (ret == HTTP_UPDATE_OK) {
      log_d("Update successful");
    }
  }

  private:
    NetworkType _networkType;
    ConnectionType _connectionType;
    HardwareSerial &_modemSerial;
    TinyGsm _modem;
    Client *_client;
};

#endif // FIRMWARE_UPDATER_H

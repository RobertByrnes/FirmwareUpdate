#ifndef FIRMWARE_UPDATE_HPP
#define FIRMWARE_UPDATE_HPP

#include <cstdint>
#include <string>
#include <sstream>
#include <fstream>
#include <Arduino.h>
#include <HTTPClient.h>
#include <SPIFFS.h>
#include <FS.h>
#include <Update.h>

namespace FirmwareUpdate {

void downloadFirmware(const std::string& firmwareUrl, const std::string& rootCaCertificate);
void performUpdate();

} // namespace FirmwareUpdate
 
#endif

void FirmwareUpdate::downloadFirmware(const std::string& firmwareUrl, const std::string& rootCaCertificate) {
  // Create an HTTP client
  HTTPClient http;

  // Set the client to use HTTPS
  http.begin(firmwareUrl.c_str(), rootCaCertificate.c_str());

  // Send the GET request
  int httpCode = http.GET();
  if (httpCode != HTTP_CODE_OK) {
    Serial.printf("Failed to download firmware file. HTTP error code: %d\n", httpCode);
    return;
  }

  // Open a file in SPIFFS to save the firmware
  File file = SPIFFS.open("/firmware.bin", "w");
  if (!file) {
    Serial.println("Failed to open firmware file for writing.");
    return;
  }

  // Write the firmware file to SPIFFS
  http.writeToStream(&file);
  file.close();

  // Open the file for reading
  std::ifstream stream("/firmware.bin", std::ios::binary);
  if (!stream.is_open()) {
    Serial.println("Failed to open firmware file for reading.");
    return;
  }

  // Read the firmware file into a string
  std::string firmware((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

  // Write the firmware file to SPIFFS
  int bytesWritten = file.write((uint8_t*)firmware.c_str(), firmware.length());
  if (bytesWritten != firmware.length()) {
    Serial.println("Failed to save firmware file to SPIFFS.");
    file.close();
    return;
  }

  // Close the file
  file.close();

  // Print a success message
  Serial.println("Firmware file downloaded and saved to SPIFFS.");
}

void FirmwareUpdate::performUpdate() {
  // Open the firmware file from SPIFFS
  File file = SPIFFS.open("/firmware.bin", "r");
  if (!file) {
    Serial.println("Failed to open firmware file for reading.");
    return;
  }

  // Set the size of the update
  uint32_t updateSize = file.size();

  // Prepare for the update
  if (!Update.begin(updateSize)) {
    Serial.println("Failed to start update.");
    file.close();
    return;
  }

  // Write the firmware file to the update
  while (updateSize > 0) {
    size_t written = Update.write(file);
    if (written > 0) {
      updateSize -= written;
    } else {
      Serial.println("Failed to write to update.");
      file.close();
      return;
    }
  }

    // Close the file
    file.close();

    // Finish the update and reboot
    if (Update.end()) {
      Serial.println("Update complete. Rebooting...");
      ESP.restart();
    } else {
      Serial.println("Failed to finish update.");
    }
}

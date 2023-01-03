#include "FirmwareUpdater.hpp"

// define log_d function if using Arduino framework
void log_d(const char* message) {
  Serial.println(message);
}

void setup() {
  // initialize serial communication
  Serial.begin(115200);
  while (!Serial);

  // create FirmwareUpdater object
  FirmwareUpdater updater(WIFI, HTTP);

  // initialize network connection
  updater.begin(PSTR("your-ssid"), PSTR("your-password"));

  // perform update
  updater.update(PSTR("http://your-update-server.com"), PSTR("update.bin"));
}

void loop() {
  // FirmwareUpdater handles updates in the background, so the loop function can be empty
}

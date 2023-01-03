#include <Arduino.h>
#include "FirmwareUpdater.hpp"

// Create a FirmwareUpdater object
FirmwareUpdater updater(TINYGSM, HTTPS, Serial1);

void setup() {
  Serial.begin(115200);
  updater.begin(PSTR("your-apn"), PSTR("your-username"), PSTR("your-password"));
  updater.update(PSTR("https://your-update-server.com"), PSTR("update.bin"));
}

void loop() {
  // Do nothing
}
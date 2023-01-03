#include "FirmwareUpdater.hpp"

// Define the log_d() function
void log_d(const char *format, ...) {
  va_list args;
  va_start(args, format);
  Serial.printf(format, args);
  va_end(args);
}

// Create a FirmwareUpdater object
FirmwareUpdater updater(WIFI, HTTPS);

void setup() {
  Serial.begin(115200);
  WiFi.begin("your-ssid", "your-password");
  updater.update(PSTR("https://your-update-server.com"), PSTR("update.bin"));
}

void loop() {
  // Do nothing
}

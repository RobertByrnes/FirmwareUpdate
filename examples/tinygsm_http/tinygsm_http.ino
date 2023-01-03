/**
 * In this example, the FirmwareUpdater object is created with TINYGSM as the network type and HTTP
 * as the connection type. The begin() function is then used to initialize the network connection 
 * using the specified APN, username, and password.
 * 
 * Finally, the update() function is called to perform the update using the specified update server 
 * and update file. The update() function will handle the download and installation of the update 
 * in the background, so the loop() function does not need to do anything.
 * 
 * Note that if you are using the Arduino framework, you will need to define the log_d() function
 * as shown in the example. The log_d() function can be used to log messages to the appropriate 
 * output (e.g. serial console, log file, etc.). If you are not using the Arduino framework,
 * you can omit the log_d() function and use your preferred method for logging messages.
 * 
 */
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
  FirmwareUpdater updater(TINYGSM, HTTP);

  // initialize network connection
  updater.begin(PSTR("your-apn"), PSTR("your-username"), PSTR("your-password"));

  // perform update
  updater.update(PSTR("http://your-update-server.com"), PSTR("update.bin"));
}

void loop() {
  // FirmwareUpdater handles updates in the background, so the loop function can be empty
}

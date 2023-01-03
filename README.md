# FirmwareUpdater Library

The FirmwareUpdater library is a simple and flexible library for updating the firmware of an ESP32 over a network connection. The library supports both WiFi and cellular (TinyGSM) connections, and can use either HTTP or HTTPS for the connection.

## Features

- Support for WiFi and TinyGSM (cellular) connections
- Support for HTTP and HTTPS connections
- Easy-to-use interface with `begin()` and `update()` functions
- Configurable logging using a log_d() function (optional)

## Installation

To use the FirmwareUpdater library, you will need to install the TinyGSM and ArduinoHttpClient libraries. You can install these libraries using the Arduino IDE's built-in library manager or by adding them as dependencies in your PlatformIO project.

Once the required libraries are installed, you can include the FirmwareUpdater library in your sketch by adding the following line at the top of your sketch:

```
#include "FirmwareUpdater.h"
```

If you are using the Arduino framework, you will also need to define the log_d() function, which you can use to log messages to the appropriate output (e.g. serial console, log file, etc.).

## Usage

To use the FirmwareUpdater library, create a `FirmwareUpdater` object and call the `begin()` and `update()` functions as needed. For example:

```
FirmwareUpdater updater(TINYGSM, HTTPS);
updater.begin(PSTR("your-apn"), PSTR("your-username"), PSTR("your-password"));
updater.update(PSTR("https://your-update-server.com"), PSTR("update.bin"));
```

This will create a `FirmwareUpdater` object that uses TinyGSM for the network connection and HTTPS for the connection type, initialize the network connection, and perform the update.

You can specify the network type (WiFi or TinyGSM) and connection type (HTTP or HTTPS) when you create the `FirmwareUpdater` object.

For example, to use WiFi and HTTP, you can do the following:

```
FirmwareUpdater updater(WIFI, HTTP);
updater.update(PSTR("http://your-update-server.com"), PSTR("update.bin"));
```

## Credits

The FirmwareUpdater library was created by [Robert Byrnes](https://github.com/RobertByrnes) and [ChatGPT](https://openai.com/blog/chatgpt/).

## License

The FirmwareUpdater library is licensed under the MIT license. See [LICENSE](LICENSE) for more information.

## Compatibility

The FirmwareUpdater library is compatible with both the Arduino IDE and PlatformIO in Visual Studio Code.

## Examples

Examples demonstrating how to use the FirmwareUpdater library are included in the examples directory of the library. You can access these examples by opening the Arduino IDE or PlatformIO in Visual Studio Code and selecting the example from the list of examples.

## Support

For support with the FirmwareUpdater library, please open an issue on the GitHub repository.

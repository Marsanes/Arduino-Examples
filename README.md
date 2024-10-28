# Arduino Examples

This is a collection of examples about common Arduino techniques. It includes:
- How to set up an LCD display.
- How to move a motor using a joystick.
- How to set up the LED matrix on the Arduino R4 board.
- How to use different sensors (humidity, temperature, pressure, UV index, LUX).
- How to connect to the Arduino IoT Cloud and upload data using WiFi.
- A complete example combining all techniques.


## Install

You will need to download the [Arduino IDE](https://www.arduino.cc/en/software), install the necessary libraries for your project, and the needed package for your specific Arduino board. Alternatively, you can use the [Arduino cloud editor](https://cloud.arduino.cc/).


## Important

To upload data to the cloud, the "secrets.h" file needs to be configured. Here is a template of how it should be set up. The "thingProperties.h" file also needs to be configured, but it is recommended to copy the contents of the provided properties file from the [Arduino IoT Cloud webpage](https://cloud.arduino.cc/). Alternatively, you can ignore these files and use the cloud editor instead of the Arduino IDE, which guides you through the process of setting up everything.


## Note

Some sensors can be used with different libraries, each having its own set of instructions. Here, I used common libraries, but some are deprecated. I will try to update them and their respective code.


## License

[MIT License](LICENSE)
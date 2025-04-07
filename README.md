# Arduino Examples Repository

This repository contains a collection of easy-to-follow Arduino examples for various sensors, modules, and functionalities. Each example is designed to help users quickly understand and implement the corresponding hardware and software.

## Table of Contents

- [Examples](#examples)
- [How to Use](#how-to-use)
- [Install](#install)
- [Important](#important)
- [Note](#note)
- [Contributing](#contributing)
- [License](#license)

## Examples

- [1-LCD](1-LCD/1-LCD.ino) - LCD display setup
- [2-Ultrasound](2-Ultrasound/2-Ultrasound.ino) - Ultrasound sensor example
- [3-StepperMotor](3-StepperMotor/3-StepperMotor.ino) - Stepper motor control
- [4-LedMatrix](4-LedMatrix/4-LedMatrix.ino) - LED matrix setup
- [5-GUVA](5-GUVA/5-GUVA.ino) - UV index sensor example
- [6-DHT](6-DHT/6-DHT.ino) - Humidity and temperature sensor
- [7-BMP280](7-BMP280/7-BMP280.ino) - Pressure sensor example
- [8-VEML7700](8-VEML7700/8-VEML7700.ino) - LUX sensor example
- [9-I2CScanner](9-I2CScanner/9-I2CScanner.ino) - I2C device scanner
- [10-IotCloud](10-IotCloud/10-IotCloud.ino) - IoT Cloud integration
- [11-WiFi](11-WiFi/11-WiFi.ino) - WiFi connection example
- [12-RFID](12-RFID/12-RFID.ino) - RFID tag reading example
- [13-SPI](13-SPI/13-SPI.ino) - SPI communication example
- [14-UART](14-UART/14-UART.ino) - UART communication example
- [15-RTC](15-RTC/15-RTC.ino) - Real-Time Clock example
- [16-OLED](16-OLED/16-OLED.ino) - OLED display example
- [17-Servo](17-Servo/17-Servo.ino) - Servo motor control example
- [18-GasSensor](18-GasSensor/18-GasSensor.ino) - Gas sensor example
- [Example Project - Atmospheric Data](Example_Project-Atmospheric_Data/Example_Project-Atmospheric_Data.ino) - Atmospheric data collection

## How to Use

1. Clone this repository to your local machine.
2. Open the desired example folder in the Arduino IDE.
3. Connect the corresponding hardware to your Arduino board.
4. Upload the sketch to your Arduino board.
5. Follow the serial monitor or hardware output for results.

## Install

You will need to download the [Arduino IDE](https://www.arduino.cc/en/software), install the necessary libraries for your project, and the needed package for your specific Arduino board. Alternatively, you can use the [Arduino cloud editor](https://cloud.arduino.cc/).

## Important

To upload data to the cloud, the "secrets.h" file needs to be configured. Here is a template of how it should be set up. The "thingProperties.h" file also needs to be configured, but it is recommended to copy the contents of the provided properties file from the [Arduino IoT Cloud webpage](https://cloud.arduino.cc/). Alternatively, you can ignore these files and use the cloud editor instead of the Arduino IDE, which guides you through the process of setting up everything.

## Note

Some sensors can be used with different libraries, each having its own set of instructions. Here, I used common libraries, but some are deprecated.

## Contributing

Contributions are welcome! If you have improvements or new examples to add, please fork this repository, make your changes, and submit a pull request.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

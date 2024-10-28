// Tutorial on how to use I2CScanner to use I2C devices. I2C devices can be all wired 
// to the same two SDA and SCL pins on the arduino. That way, by only using two data  
// pins, you can connect multiple devices to the arduino. Of course, all devices must 
// have different addresses, be compatible with I2C, and be connected to a power source

// Wire library is installed by default in the arduino IDE
#include <Wire.h>

void setup() {
  // Initialize the wire library
  Wire.begin();

  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;

  // Scans for devices from address 1 to 127 and prints the address of the device.
  for (address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");

      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }

  delay(2500);
}
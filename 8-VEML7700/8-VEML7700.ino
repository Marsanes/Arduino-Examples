// Example for the Adafruit VEML7700 Lux sensor
// Library: Adafruit VEML7700 (by Adafruit)
#include <Adafruit_VEML7700.h>

// Create the VEML7700 sensor object
Adafruit_VEML7700 veml = Adafruit_VEML7700();

void setup() {
  Serial.begin(9600);
  veml.begin();
}

void loop() {
  float lux = veml.readLux(VEML_LUX_AUTO);
  Serial.print("Lux = ");
  Serial.println(lux);
  
  delay(2000);
}
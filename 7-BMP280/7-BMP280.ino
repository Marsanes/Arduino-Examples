// Example for the BMP280 pressure sensor

#include <BMP280_DEV.h>

float temperature, pressure, altitude;
BMP280_DEV bmp280;

void setup() {
  Serial.begin(9600);
  bmp280.begin(BMP280_I2C_ALT_ADDR);
}

void loop() {
  bmp280.startForcedConversion();
  bmp280.getCurrentMeasurements(temperature, pressure, altitude);
  Serial.print(temperature);
  Serial.print(F("*C   "));
  Serial.print(pressure);
  Serial.print(F("hPa   "));
  Serial.print(altitude);
  Serial.println(F("m"));

  delay(2000);
}
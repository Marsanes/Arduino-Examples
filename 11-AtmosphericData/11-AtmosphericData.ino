// Example of a complete sketch that reads from the following sensors:
// - DHT22 (temperature and humidity)
// - BMP280 (temperature, pressure and altitude)
// - VEML7700 (light)
// - UV sensor
// The data is uploaded to the Arduino IoT Cloud to be visualized in a dashboard.
// It can also be viewed in a phone using the Arduino "IoT Remote" app.
// This sketch combines the techniques from the previous sketches.

#include <DHT.h>
#include <BMP280_DEV.h>
#include <Adafruit_VEML7700.h>
#include "thingProperties.h"


#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float temp, pres, altitude;
BMP280_DEV bmp280;

Adafruit_VEML7700 veml = Adafruit_VEML7700();

void setup() {
  Serial.begin(9600);
  bmp280.begin(BMP280_I2C_ALT_ADDR);
  dht.begin();
  veml.begin();
  delay(2000);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C");

  float sensorVoltage, sensorValue, uvindex;
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024.0*3.3;
  if(sensorVoltage < 46) {
    uvindex = 0;
  } else {
    uvindex = (sensorVoltage * 0.01072166) - 1.401623612;
  }

  Serial.print("UV: ");
  Serial.println(uvindex);
    
  bmp280.startForcedConversion();
  bmp280.getCurrentMeasurements(temp, pres, altitude);
  Serial.print(temp);
  Serial.print(F("*C   "));
  Serial.print(pres);
  Serial.print(F("hPa   "));
  Serial.print(altitude);
  Serial.println(F("m"));

  float light = veml.readLux(VEML_LUX_AUTO);
  Serial.print("Lux = ");
  Serial.println(light);

  humidity = h;
  temperature = t;
  pressure = pres;
  lux = light;
  uv_index = uvindex;
  
  ArduinoCloud.update();
  delay(2000);
}
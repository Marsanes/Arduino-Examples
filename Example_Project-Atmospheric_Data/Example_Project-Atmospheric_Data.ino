// Complete example sketch for atmospheric data collection
// This sketch reads data from multiple sensors and uploads it to the Arduino IoT Cloud.
// Sensors used:
// - DHT22: Measures temperature and humidity
// - BMP280: Measures temperature, pressure, and altitude
// - VEML7700: Measures light intensity (lux)
// - UV sensor: Measures UV index
// Data can be visualized on the Arduino IoT Cloud dashboard or the "IoT Remote" app.

#include <DHT.h>
#include <BMP280_DEV.h>
#include <Adafruit_VEML7700.h>
#include "thingProperties.h"

// DHT22 sensor configuration
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// BMP280 sensor configuration
float temp, pres, altitude;
BMP280_DEV bmp280;

// VEML7700 light sensor configuration
Adafruit_VEML7700 veml = Adafruit_VEML7700();

void setup()
{
  // Start serial communication for debugging
  Serial.begin(9600);

  // Initialize sensors
  bmp280.begin(BMP280_I2C_ALT_ADDR);
  dht.begin();
  veml.begin();
  delay(2000); // Allow sensors to stabilize

  // Initialize IoT Cloud properties
  initProperties();

  // Start the Arduino IoT Cloud connection
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Set debug message level and print debug information
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  // Read data from the DHT22 sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Print DHT22 data to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // Read data from the UV sensor
  float sensorVoltage, sensorValue, uvindex;
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue / 1024.0 * 3.3;
  if (sensorVoltage < 46)
  {
    uvindex = 0;
  }
  else
  {
    uvindex = (sensorVoltage * 0.01072166) - 1.401623612;
  }

  // Print UV index to the serial monitor
  Serial.print("UV: ");
  Serial.println(uvindex);

  // Read data from the BMP280 sensor
  bmp280.startForcedConversion();
  bmp280.getCurrentMeasurements(temp, pres, altitude);

  // Print BMP280 data to the serial monitor
  Serial.print(temp);
  Serial.print(F("*C   "));
  Serial.print(pres);
  Serial.print(F("hPa   "));
  Serial.print(altitude);
  Serial.println(F("m"));

  // Read data from the VEML7700 light sensor
  float light = veml.readLux(VEML_LUX_AUTO);

  // Print light intensity to the serial monitor
  Serial.print("Lux = ");
  Serial.println(light);

  // Update IoT Cloud variables
  humidity = h;
  temperature = t;
  pressure = pres;
  lux = light;
  uv_index = uvindex;

  // Update the IoT Cloud connection
  ArduinoCloud.update();

  // Wait for 2 seconds before the next reading
  delay(2000);
}
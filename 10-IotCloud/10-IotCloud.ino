// Tutorial for connecting the arduino to the Arduini IoT Cloud

// Include the thingProperties file needed for the cloud connection
#include "thingProperties.h"
#include "DHT.h"

// In this case, we will upload the temperature and humidity values from a DHT11 sensor

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();
  
  if (isnan(humi) || isnan(tempC)){
    Serial.println("Failed to read from DHT sensor!");
  } else {
    humidity = humi;
    temperature = tempC;
  }

  delay(3000);
}
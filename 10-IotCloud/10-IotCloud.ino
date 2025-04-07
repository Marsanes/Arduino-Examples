// Tutorial for connecting the Arduino to the Arduino IoT Cloud

// Include the necessary files for cloud connection and sensor functionality
#include "thingProperties.h" // Contains IoT Cloud properties
#include "DHT.h"             // Library for the DHT sensor

// Define the DHT sensor pin and type
#define DHTPIN 7
#define DHTTYPE DHT11

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // Start the serial communication for debugging
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
  delay(1500); // Allow the sensor to stabilize

  // Initialize IoT Cloud properties
  initProperties();

  // Start the Arduino IoT Cloud connection
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Set the debug message level and print debug information
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  // Update the IoT Cloud connection
  ArduinoCloud.update();

  // Read humidity and temperature from the DHT sensor
  float humi = dht.readHumidity();
  float tempC = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(humi) || isnan(tempC))
  {
    Serial.println("Failed to read from DHT sensor!");
  }
  else
  {
    // Update the IoT Cloud variables
    humidity = humi;
    temperature = tempC;
  }

  // Wait for 3 seconds before the next reading
  delay(3000);
}
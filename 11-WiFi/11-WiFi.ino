// Example for ESP8266/ESP32 WiFi connection
#include <WiFi.h>

// Replace with your network credentials
const char *ssid = "Your_SSID";         // Your WiFi SSID
const char *password = "Your_PASSWORD"; // Your WiFi password

void setup()
{
    Serial.begin(115200); // Start the serial communication at 115200 baud rate

    // Begin WiFi connection
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    // Wait until the device is connected to WiFi
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    // Print a success message once connected
    Serial.println("\nConnected to WiFi");
}

void loop()
{
    // Add your code here to perform tasks while connected to WiFi
}
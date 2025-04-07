// Example for Real-Time Clock (RTC) using DS3231
#include <Wire.h>   // Include Wire library for I2C communication
#include <RTClib.h> // Include RTClib library for RTC module

RTC_DS3231 rtc; // Create an instance of the RTC_DS3231 class

void setup()
{
    Serial.begin(9600); // Start serial communication at 9600 baud rate

    // Check if the RTC module is connected
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC"); // Print error message if RTC is not found
        while (1)
            ; // Stop execution
    }

    // Check if the RTC lost power and set the time if necessary
    if (rtc.lostPower())
    {
        Serial.println("RTC lost power, setting the time!"); // Print message
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));      // Set the RTC to the current date and time
    }
}

void loop()
{
    DateTime now = rtc.now(); // Get the current date and time from the RTC

    // Print the current date and time to the Serial monitor
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    delay(1000); // Wait for 1 second before printing the next value
}
// Example for SPI communication
#include <SPI.h> // Include SPI library for communication

void setup()
{
    Serial.begin(9600);                              // Start serial communication at 9600 baud rate
    SPI.begin();                                     // Initialize SPI bus
    pinMode(SS, OUTPUT);                             // Set Slave Select (SS) pin as output
    digitalWrite(SS, HIGH);                          // Set SS pin to HIGH (inactive state)
    Serial.println("SPI communication initialized"); // Print initialization message
}

void loop()
{
    digitalWrite(SS, LOW);  // Activate the slave device by setting SS to LOW
    SPI.transfer(0x42);     // Send a byte of data (0x42 is an example value)
    digitalWrite(SS, HIGH); // Deactivate the slave device by setting SS to HIGH
    delay(1000);            // Wait for 1 second before sending the next byte
}
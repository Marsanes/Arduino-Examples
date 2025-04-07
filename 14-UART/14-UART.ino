// Example for UART communication
void setup()
{
    Serial.begin(9600);                               // Start serial communication at 9600 baud rate
    Serial1.begin(9600);                              // Start UART communication on Serial1 at 9600 baud rate
    Serial.println("UART communication initialized"); // Print initialization message
}

void loop()
{
    // Check if data is available on the Serial monitor
    if (Serial.available())
    {
        char data = Serial.read(); // Read a character from Serial
        Serial1.write(data);       // Send the character to Serial1
    }

    // Check if data is available on Serial1
    if (Serial1.available())
    {
        char data = Serial1.read(); // Read a character from Serial1
        Serial.write(data);         // Send the character to the Serial monitor
    }
}
// Example for RFID reader using MFRC522
#include <SPI.h>     // Include SPI library for communication
#include <MFRC522.h> // Include MFRC522 library for RFID module

// Define pins for the RFID module
#define RST_PIN 9 // Reset pin
#define SS_PIN 10 // Slave select pin

// Create an instance of the MFRC522 class
MFRC522 rfid(SS_PIN, RST_PIN);

void setup()
{
    Serial.begin(9600);                                   // Start serial communication at 9600 baud rate
    SPI.begin();                                          // Initialize SPI bus
    rfid.PCD_Init();                                      // Initialize the RFID module
    Serial.println("Place your card near the reader..."); // Prompt user to place an RFID card
}

void loop()
{
    // Check if a new card is present
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    {
        return; // Exit if no card is detected
    }

    // Print the UID of the card
    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "); // Add leading zero for single-digit values
        Serial.print(rfid.uid.uidByte[i], HEX);                // Print UID in hexadecimal format
    }
    Serial.println();

    rfid.PICC_HaltA(); // Halt the card to allow reading another card
}
/*
  LiquidCrystal Library Example
  This example demonstrates how to use the LiquidCrystal library to control an LCD.

  Circuit:
  * LCD RS pin to digital pin 7
  * LCD Enable pin to digital pin 6
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K potentiometer:
    - Ends connected to +5V and ground
    - Wiper connected to LCD VO pin (pin 3 for contrast adjustment)
*/

// Include the LiquidCrystal library
#include <LiquidCrystal.h>

// Initialize the library with the pins connected to the LCD
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  // Set up the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
  // Display a static message on the first row
  lcd.print("hello, world!");
}

void loop()
{
  // Move the cursor to the first column of the second row
  lcd.setCursor(0, 1);
  // Display the number of seconds since the Arduino was reset
  lcd.print(millis() / 1000);
}
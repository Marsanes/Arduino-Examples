// Example for OLED display using Adafruit SSD1306
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C))
    {
        Serial.println("SSD1306 allocation failed");
        for (;;)
            ;
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Hello, OLED!");
    display.display();
}

void loop()
{
    // Add your code here
}
// Stepper Motor Control using Joystick and Arduino

#include <LiquidCrystal.h>
#include <Servo.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo servo;

#define VRX_PIN  A1 // Arduino pin connected to VRX pin
#define VRY_PIN  A0 // Arduino pin connected to VRY pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int angle = 0; // To store the angle of the servo motor

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2); // initialize the lcd for 16 chars 2 lines
    servo.attach(9); 
    servo.write(0);
}

void loop() {
    // read analog X and Y analog values
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);

    int x = map(xValue, 0, 1023, -255, 255); // map the value to a range of -255 to 255
    int y = map(yValue, 0, 1023, 255, -255); // map the value to a range of -255 to 255

    int angle = map(yValue, 0, 1023, 0, 180);

    servo.write(angle);

    // print data to Serial Monitor on Arduino IDE
    Serial.print("x = ");
    Serial.print(x);
    Serial.print(", y = ");
    Serial.println(y);

    // print data to LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("x = ");
    lcd.print(x);
    lcd.setCursor(0, 1);
    lcd.print("y = ");
    lcd.print(y);

    delay(200);
}
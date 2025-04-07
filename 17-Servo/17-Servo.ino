// Example for controlling a servo motor
#include <Servo.h>

Servo myServo;

void setup()
{
    myServo.attach(9); // Attach servo to pin 9
    Serial.begin(9600);
}

void loop()
{
    for (int pos = 0; pos <= 180; pos += 1)
    {
        myServo.write(pos);
        delay(15);
    }
    for (int pos = 180; pos >= 0; pos -= 1)
    {
        myServo.write(pos);
        delay(15);
    }
}
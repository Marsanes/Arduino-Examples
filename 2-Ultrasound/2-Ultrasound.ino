// HC-SR04 example sketch

#include <LiquidCrystal.h>

const int trigPin = 12;
const int echoPin = 11;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

float duration, distance;
float distances[10] = {0};
int index = 0;
float sum = 0;


void setup() {
    // Set the trigPin as an output and the echoPin as an input
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    // Start the serial communication for the serial monitor and the lcd
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop() {
    // Set  the trigPin high for 10 microseconds for the sensor to send the ultrasonic wave
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin, which will be high for the time it took for the wave to return
    duration = pulseIn(echoPin, HIGH);
    // Calculate the distance based on the duration and the average speed of sound
    distance = (duration * 1.715) / 10;

    // Print the distance in the serial monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    
    // Print the distance in the LCD
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);

    // Take 0.5s between each reading
    delay(500);
}
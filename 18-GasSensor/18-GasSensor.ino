// Example for gas sensor (MQ-series)
const int gasSensorPin = A0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Gas sensor initialized");
}

void loop()
{
    int sensorValue = analogRead(gasSensorPin);
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print("\tVoltage: ");
    Serial.println(voltage);
    delay(1000);
}
// Example code for the GUVA UV sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  float sensorVoltage, sensorValue, uvindex;
  
  // Read the sensor value (from 0 to 1024)
  sensorValue = analogRead(A0);

  // IMPORTANT: Convert the sensor value to a voltage
  // 3.3 is the voltage that the ESP8266 uses, so we use that for the conversion
  // If you are using a 5V board (like the Arduino Uno), you should use 5.0
  sensorVoltage = sensorValue/1024.0 * 3.3; //sensorValue/1024.0 * 5.0;

  // Round very low values to 0
  if(sensorValue < 46) {
    
    uvindex = 0;
  } else {
    // Calculate the UV index using the formula provided in the sensor datasheet
    uvindex = (sensorValue - 25.8) / 19.427;
  }

  Serial.print("UV: ");
  Serial.println(uvindex);
  delay(1000);
}
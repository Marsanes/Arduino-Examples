#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "secrets.h"

const char DEVICE_ID[]  = SECRET_DEVICE_ID;
const char DEVICE_KEY[] = SECRET_DEVICE_KEY;
const char SSID[] = SECRET_SSID;
const char PASS[] = SECRET_OPTIONAL_PASS;

CloudTemperatureSensor temperature;
CloudRelativeHumidity humidity;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_ID);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(temperature, READ, 3 * SECONDS, NULL);
  ArduinoCloud.addProperty(humidity, READ, 3 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
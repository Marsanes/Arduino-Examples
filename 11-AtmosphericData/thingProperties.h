#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "secrets.h"

const char THING_DEVICE_ID[] = SECRET_DEVICE_ID    ;
const char DEVICE_KEY     [] = SECRET_DEVICE_KEY   ;
const char SSID           [] = SECRET_SSID         ;
const char PASS           [] = SECRET_OPTIONAL_PASS;

float lux;
float uv_index;
CloudTemperatureSensor temperature;
CloudRelativeHumidity  humidity   ;
CloudPressure          pressure   ;

void initProperties(){
  ArduinoCloud.setBoardId(THING_DEVICE_ID);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(lux        , READ, 2 * SECONDS, NULL);
  ArduinoCloud.addProperty(uv_index   , READ, 2 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperature, READ, 2 * SECONDS, NULL);
  ArduinoCloud.addProperty(humidity   , READ, 2 * SECONDS, NULL);
  ArduinoCloud.addProperty(pressure   , READ, 2 * SECONDS, NULL);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
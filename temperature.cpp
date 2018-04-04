#include "temperature.h"

Temperature::Temperature(uint8_t pin) {
    oneWire = new OneWire(pin);
    sensors = DallasTemperature(oneWire);
    setUpSensors();
}

void Temperature::setUpSensors() {
  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();
  for(int i = 0; i < numberOfDevices; i++) {
    if(sensors.getAddress(tempDeviceAddress, i)) {
       sensors.setResolution(tempDeviceAddress, 11);
    }
  }
}


float Temperature::getTemp() {
  sensors.requestTemperatures();
  float sum;
  for (int i = 0; i < numberOfDevices; i++) {
    float temp = sensors.getTempCByIndex(i);
    sum += temp;
  }
  return sum / numberOfDevices;
}

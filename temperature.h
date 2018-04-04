// https://github.com/milesburton/Arduino-Temperature-Control-Library
#include <DallasTemperature.h>
// https://github.com/PaulStoffregen/OneWire
#include <OneWire.h>

class Temperature {
public:
    Temperature(uint8_t pin);
    void setUpSensors();
    float getTemp();
private:
    OneWire *oneWire;
    DallasTemperature sensors;
    int numberOfDevices;
    DeviceAddress tempDeviceAddress;
};

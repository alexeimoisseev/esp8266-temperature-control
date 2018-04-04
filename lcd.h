#include <Wire.h>
//https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
#include <LiquidCrystal_I2C.h>

class Lcd {
public:
    Lcd();
    void print(float, float, bool);
    void print(String);
private:
    LiquidCrystal_I2C *lcd;
};

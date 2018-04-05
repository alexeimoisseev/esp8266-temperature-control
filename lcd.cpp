#include "lcd.h"
Lcd::Lcd() {
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    lcd->begin();
}

Lcd::~Lcd() {
    delete lcd;
}

void Lcd::print(float temp, float target, bool fanOn) {
    lcd->clear();
    lcd->print("Temp ");
    lcd->print(temp);
    lcd->print("C");
    lcd->setCursor(0,1);
    lcd->print("Tgt ");
    lcd->print(target);
    lcd->print(" fan ");
    if (fanOn) {
        lcd->print("on");
    } else {
        lcd->print("off");
    }
}

void Lcd::print(String s) {
    lcd->clear();
    lcd->print(s);
}

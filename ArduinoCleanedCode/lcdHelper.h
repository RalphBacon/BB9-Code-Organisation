#pragma once

#include "globals.h"
#include <LiquidCrystal_I2C.h>

namespace lcd {

// Start the LCD with correct HEX address
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setUpLcd() {
    // Set up LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0); // col, row
    lcd.print("Hello World");
}

void printTemperature(float currTemp) {
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(currTemp);
    printf("Temperature: %5.2f   \n", currTemp);
}

} // namespace lcd
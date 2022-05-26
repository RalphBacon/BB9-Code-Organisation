/*
Video #244: separate header files, namespaces
*/
#include <Arduino.h>
#include <LibPrintf.h>
#include <Wire.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <DS18B20.h>

// Pin that the DS18b20 is connected to
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

// Trigger pin to emulate request to get temperature
#define pinBtn 3

// Start the LCD with correct HEX address
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Setup
void setup() {

    // Serial Monitor
    Serial.begin(115200);
    delay(500);

    // Push button
    pinMode(pinBtn, INPUT_PULLUP);

    // Set up LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0); // col, row
    lcd.print("Hello World");

    // Start sensor DS18B20 in 10-bit mode
    sensor.begin();
    sensor.setResolution(10);

    // All done
    Serial.println("Setup completed");
}

void loop() {

    // Wait for push button press
    if (digitalRead(pinBtn) == LOW) {

        // Request temperature and wait until complete
        sensor.requestTemperatures();
        Serial.println("Requesting temp");
        while (!sensor.isConversionComplete())
            ;

        // Get temperature (float)
        float currTemp = sensor.getTempC();

        // Print out temperature on LCD
        lcd.setCursor(0, 1);
        lcd.print("Temp:");
        lcd.print(currTemp);
        printf("Temperature: %5.2f   \n", currTemp);
    }
}

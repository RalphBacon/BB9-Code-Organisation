/*
Video #244: separate header files, namespaces
*/
#include "globals.h"
#include "sensorHelper.h"
#include "lcdHelper.h"

// Setup
void setup() {

    // Serial Monitor
    Serial.begin(115200);

    // Initialise LCD
    lcd::setUpLcd();

    // Initialise sensor
    sensor::setupSensor();

    // All done
    Serial.println("Setup completed");
}

void loop() {

    // Wait for push button press
    if (PUSH_BUTTON_PRESSED) {

        // Request temperature and wait until complete
        float currTemp = sensor::getTemperature();

        // Print out temperature on LCD
        lcd::printTemperature(currTemp);
    }
}

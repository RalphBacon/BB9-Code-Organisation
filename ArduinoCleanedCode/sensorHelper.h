#pragma once

#include "globals.h"
#include <Wire.h>
#include <OneWire.h>
#include <DS18B20.h>

namespace sensor {

// Pin that the DS18b20 is connected to
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

}

// sdf;oaskf;alsdfk;alsdfk;asdk sadf;lk

using namespace buttons;

namespace sensor {

// Initialise sensor
void setupSensor() {
    // Push button
    pinMode(pinBtn, INPUT_PULLUP);

    // Start sensor DS18B20 in 10-bit mode
    sensor.begin();
    sensor.setResolution(10);
}

// Read sensor
float getTemperature() {
    sensor.requestTemperatures();
    Serial.println("Requesting temp");
    while (!sensor.isConversionComplete())
        ;

    a++;

    // Get temperature (float)
    return sensor.getTempC();
}

} // namespace sensor
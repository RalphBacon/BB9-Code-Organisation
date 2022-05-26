#pragma once

#include <Arduino.h>
#include <LibPrintf.h>

namespace buttons {

// Trigger pin to emulate request to get temperature
// #define pinBtn 3 <-------- Note that #define statements are not subject to ns rules
const uint8_t pinBtn = 3;


}

#define PUSH_BUTTON_PRESSED (digitalRead(buttons::pinBtn) == LOW)
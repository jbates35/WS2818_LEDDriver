#include <Arduino.h>

#include "LEDDrive.h"

//Initial objects & structs
LEDDriver led;

void setup() {
  led.init();
  led.changeMode(LED_SWIRL);
}

void loop() {
  led.run();
}
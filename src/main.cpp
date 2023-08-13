#include <Arduino.h>

extern "C" {
  #include "LEDDrive.h"
}

//Initial objects & structs
struct LEDStruct led1;

void setup() {
  LED_init(&led1, 13, LOW);
}

void loop() {
  LED_toggle(&led1);
  delay(1000);
}
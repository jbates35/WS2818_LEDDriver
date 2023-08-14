#include <Arduino.h>

#include "LEDDrive.h"

//Initial objects & structs
LEDDriver led;

void setup() {
  Serial.begin(9600);

  led.init(6);
}

void loop() {
  led.run();

  if(led.getMode() == LED_OFF)
  {
    led.changeMode(LED_ON);
  }
  else
  {
    led.changeMode(LED_OFF);
  }

  delay(1000);

}
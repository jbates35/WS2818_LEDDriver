#include "LEDDrive.h"

#include <Arduino.h>

void LED_init(struct LEDStruct *led, int pin, int state)
{
    led->pin = pin;
    led->state = state;

    pinMode(led->pin, OUTPUT);
    digitalWrite(led->pin, state);
}

void LED_changeState(struct LEDStruct *led, int state)
{
    led->state = state;
    digitalWrite(led->pin, led->state);
}

void LED_toggle(struct LEDStruct *led)
{
    led->state = !(led->state);
    digitalWrite(led->pin, led->state);
}

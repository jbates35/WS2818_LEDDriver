#include "LEDDrive.h"

#include <Arduino.h>

LEDDriver::LEDDriver()
{
    //Set function pointers to mode
    modeFunc[LED_OFF] = &LEDDriver::_ledsOff;
    modeFunc[LED_ON] = &LEDDriver::_ledsOn;
    // modeFunc[LED_SWIRL] = _ledsSwirl;
}

LEDDriver::~LEDDriver()
{
}

void LEDDriver::init(int pin)
{
    this->mode = LED_OFF;
    this->brightness = BRIGHT_MAX;
    this->speed = LED_NORMAL;

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void LEDDriver::run()
{
    //Set out vals based on in vals


    (this->*modeFunc[mode])();
    FastLED.show();
}

void LEDDriver::_ledsOff()
{
    for(CRGB &thisLed : leds)
    {
        thisLed = CRGB(0, 0, 0);
    }
}

void LEDDriver::_ledsOn()
{
    for(CRGB &thisLed : leds)
    {
        thisLed = CRGB(0,0,255);
    }
}

void LEDDriver::_ledsSwirl()
{

}
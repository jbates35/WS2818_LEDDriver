#include "LEDDrive.h"

#include <Arduino.h>

LEDDriver::LEDDriver()
{
    //Set function pointers to mode
    modeFunc[LED_OFF] = &LEDDriver::_ledsOff;
    modeFunc[LED_ON] = &LEDDriver::_ledsOn;
    modeFunc[LED_SWIRL] = &LEDDriver::_ledsSwirl;
}

LEDDriver::~LEDDriver()
{
}

void LEDDriver::init()
{
    mode = LED_OFF;
    brightness = BRIGHT_MAX;
    speed = LED_NORMAL;
    tick = 0;
    brightDir = 0;

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void LEDDriver::run()
{
    //Rest of function should be done periodically
    if(millis() - refreshMs < (1000/REFRESH_HZ))
        return;
        
    refreshMs = millis();

    //Set out vals based on in vals
    (this->*modeFunc[mode])();

    tick++;
    if(tick > MAX_TICK)
        tick = 0;
    
    //Update LEDs
    for(int i = 0; i < NUM_LEDS; i++)
    {
        val[i].r = (float) raw[i].r * (brightness/BRIGHT_MAX);
        val[i].g = (float) raw[i].g * (brightness/BRIGHT_MAX);
        val[i].b = (float) raw[i].b * (brightness/BRIGHT_MAX);

        leds[i] = CRGB(val[i].r, val[i].g, val[i].b);
    }

    FastLED.show();
}

void LEDDriver::_ledsOff()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        raw[i].r = 0;
        raw[i].g = 0;
        raw[i].b = 0;
    }
}

void LEDDriver::_ledsOn()
{
}

void LEDDriver::_ledsSwirl()
{
    int arrCount = tick * (NUM_LEDS * 5.0/MAX_TICK);

    if(tick==0)
        brightDir = !brightDir;
    
    int brightTerm;

    if(brightDir == 0)
        brightTerm = tick * (640.0/MAX_TICK) - 513;
    else
        brightTerm = (MAX_TICK - tick) * (640.0/MAX_TICK) - 513;

    if(brightTerm < 0)
        brightTerm = 0;

    brightness = 128 + brightTerm;

    //First set all to the base colour
    for(int i = 0; i < NUM_LEDS; i++)
    {
        _setVal(i, 255, 0, 70);
    }
    
    _setVal(arrCount, 170, 35, 120);
    _setVal(arrCount+1, 80, 70, 180);
    _setVal(arrCount+2, 0, 105, 255);
    _setVal(arrCount+3, 80, 70, 180);
    _setVal(arrCount+4, 170, 35, 120);
}

void LEDDriver::_setVal(int led, int r, int g, int b)
{
    if(led < 0 || led >= NUM_LEDS)
        return;

    raw[led].r = r;
    raw[led].g = g;
    raw[led].b = b;
}
#pragma once

#include <FastLED.h>

#define LED_PIN 7

#define NUM_LEDS 16

#define BRIGHT_MAX 255.0
#define BRIGHT_MIN 0

#define REFRESH_HZ 100

#define MAX_TICK 900.0

enum {
    LED_OFF = 0,
    LED_ON,
    LED_SWIRL
};

enum {
    LED_SLOW = 0,
    LED_NORMAL,
    LED_FAST
};

enum {
    LED_RED = 0,
    LED_GREEN,
    LED_BLUE,
    LED_YELLOW,
    LED_PURPLE,
    LED_CYAN,
    LED_WHITE
};

typedef struct LEDVals {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} LEDVals;

class LEDDriver {

private:
    int mode, modePrev;    
    float brightness;
    int speed;
    int color;

    long refreshMs;
    int tick;
    int brightDir;

    LEDVals raw[NUM_LEDS];
    LEDVals val[NUM_LEDS];
    CRGB leds[NUM_LEDS];

    //Function pointers with diff functions for diff modes
    typedef void (LEDDriver::*ModeFunc)();
    ModeFunc modeFunc[3];

    void _ledsOff(void);
    void _ledsOn(void);
    void _ledsSwirl(void);

    void _setVal(int led, int r, int g, int b);

public:

    LEDDriver();
    ~LEDDriver();

    /**
     * @brief Initialize LEDStruct
     * 
     * @param led Struct of LED which will be initialized
     * @param pin Pin of LED
     * @param mode Initial mode of LED
     */
    void init();

    /**
     * @brief Run LED program in program loop
     */
    void run();

    /**
     * @brief Change mode of LED
     * 
     * @param led Struct of LED which will be changed
     * @param mode New mode of LED
     */
    void changeMode(int mode) {
        this->mode = mode;
    }

    /**
     * @brief Get the Mode object
     * 
     * @return int - Mode of LED
     */
    int getMode() {
        return this->mode;
    }

    /**
     * @brief Set the Brightness object
     * 
     * @param brightness 
     */
    void setBrightness(int brightness) {
        this->brightness = brightness;
    }

    /**
     * @brief Get the Brightness object
     * 
     * @return int - Brightness of LED
     */
    int getBrightness() {
        return this->brightness;
    }

    /**
     * @brief Set the Speed object
     * 
     * @param speed 
     */
    void setSpeed(int speed) {
        this->speed = speed;
    }

    /**
     * @brief Get the Speed object
     * 
     * @return int - Speed of LED
     */
    int getSpeed() {
        return this->speed;
    }

    /**
     * @brief Set the Color object
     * 
     * @param color 
     */
    void setColor(int color) {
        this->color = color;
    }

    /**
     * @brief Get the Color object
     * 
     * @return int - Color of LED
     */
    int getColor() {
        return this->color;
    }

};
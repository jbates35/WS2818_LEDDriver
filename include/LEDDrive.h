#ifndef LED_DRIVE_H
#define LED_DRIVE_H

struct LEDStruct {
    int pin;
    int state;
};

/**
 * @brief Initialize LEDStruct
 * 
 * @param led Struct of LED which will be initialized
 * @param pin Pin of LED
 * @param state Initial state of LED
 */
void LED_init(struct LEDStruct *led, int pin, int state);

/**
 * @brief Change state of LED
 * 
 * @param led Struct of LED which will be changed
 * @param state New state of LED
 */
void LED_changeState(struct LEDStruct *led, int state);

/**
 * @brief Toggle state of LED
 * 
 * @param led Struct of LED which will be toggled
 */
void LED_toggle(struct LEDStruct *led);

#endif
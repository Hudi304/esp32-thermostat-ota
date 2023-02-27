
#ifndef VARIABLES_H
#define VARIABLES_H

#include "Arduino.h"
#include "pin.h"

#define DEBUG_MODE true

#define MAX_LONG 0xffffffff

#define CHECK_TEMP_EVERY 1

// GPIO 4 (D4) (right side 5th)
extern const int ONE_WIRE_BUS;

extern const int RELAY_PIN; // 26
extern bool heater_pin_state;

// GPIO 2 (__) (not exposed)
extern const int LED_BUILTIN; // 2
extern bool status_led_state;

extern Pin builtin_led;

extern unsigned long sec_since_on;
extern unsigned long curr_millis;
extern unsigned long prev_millis;

extern bool board_status_led;
extern bool status;

extern unsigned long curr_check_no;
extern unsigned long prev_check_no;

extern float min_temp;
extern float ambient_t_C;
extern float max_temp;

enum HEATER_STATE
{
    UNDER_MIN = 0,
    HEATING_UP = 1,
    OVER_MAX = 2,
    COOLING_OFF = 3,
};

extern HEATER_STATE state;
extern const char server_url[12];

#endif

#ifndef VARIABLES_H
#define VARIABLES_H

#define MAX_LONG 0xffffffff
#define RELAY_PIN 26
#define LED_BUILTIN 2

#define DEBUG_MODE true
#define ONE_WIRE_BUS 4 // as we connected it on D2 the GPIO of it is 4 (Check NodeMCU pinout)

extern unsigned long sec_since_on;
extern unsigned long curr_millis;
extern unsigned long prev_millis;

extern bool board_status_led;
extern bool status;

extern unsigned long curr_check_no;
extern unsigned long prev_check_no;

extern float start_at_temp_C;
extern float ambient_t_C;
extern float stop_at_temp_C;

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
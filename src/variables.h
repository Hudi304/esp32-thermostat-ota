#ifndef VARIABLES
#define VARIABLES

#define MAX_LONG 0xffffffff
#define RELAY_PIN 5
#define LED_BUILTIN 2

unsigned long sec_since_on = 0;
unsigned long curr_millis = 0;
unsigned long prev_millis = 0;

bool ledOn;
bool status;

unsigned long curr_check_no = 0;
unsigned long prev_check_no = 0;

float start_at_temp_C = 19;
float ambient_t_C = 20;
float stop_at_temp_C = 22;

const char server_url[12] = "thermostat";

enum HEATER_STATE
{
    UNDER_MIN = 0,
    HEATING_UP = 1,
    OVER_MAX = 2,
    COOLING_OFF = 3,
};

HEATER_STATE state = COOLING_OFF;

#endif

#include "variables.h"

unsigned long sec_since_on = 0;
unsigned long curr_millis = 0;
unsigned long prev_millis = 0;

bool board_status_led = false;
bool status = false;

unsigned long curr_check_no = 0;
unsigned long prev_check_no = 0;

float min_temp = 19;
float ambient_t_C = 20;
float max_temp = 22;

extern const char server_url[12] = "thermostat";

//
HEATER_STATE state = COOLING_OFF;
bool heater_pin_state = HIGH;
const int ONE_WIRE_BUS = 4;

bool status_led_state = HIGH;
const int LED_BUILTIN = 2;

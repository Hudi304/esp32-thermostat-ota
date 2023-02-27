#include "variables.h"
// TODO clean this
//  there are things that are declared here and are not used

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

HEATER_STATE state = COOLING_OFF;

const int RELAY_PIN = 26; // 26
bool heater_pin_state = HIGH;
const int ONE_WIRE_BUS = 4;

bool status_led_state = HIGH;
const int LED_BUILTIN = 2;

// TODO test this implementation
// Pin builtin_led = Pin(2, OUTPUT, true);
// Pin builtin_led = Pin(26, OUTPUT, true);

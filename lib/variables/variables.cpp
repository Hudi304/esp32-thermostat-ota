#include "variables.h"

unsigned long sec_since_on = 0;
unsigned long curr_millis = 0;
unsigned long prev_millis = 0;

bool board_status_led = false;
bool status = false;

unsigned long curr_check_no = 0;
unsigned long prev_check_no = 0;

float start_at_temp_C = 19;
float ambient_t_C = 20;
float stop_at_temp_C = 22;

extern const char server_url[12] = "thermostat";

HEATER_STATE state = COOLING_OFF;
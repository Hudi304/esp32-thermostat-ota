The header file can be included in any source file that needs access to these global variables and enumerations. To access the variables, simply use the variable name as defined in this header file.

Example:

#include "variables.h"

unsigned long sec_since_on = 0;

void increment_time() {
    sec_since_on++;
}

Global Variables
sec_since_on
An unsigned long that represents the number of seconds since the device was last turned on.

curr_millis
An unsigned long that represents the current value of the millis timer.

prev_millis
An unsigned long that represents the previous value of the millis timer.

board_status_led
A boolean value that indicates the current state of the board's status LED.

status
A boolean value that indicates the current status of the device.

curr_check_no
An unsigned long that represents the current check number.

prev_check_no
An unsigned long that represents the previous check number.

start_at_temp_C
A float value that represents the temperature at which the heating process should start.

ambient_t_C
A float value that represents the current ambient temperature.

stop_at_temp_C
A float value that represents the temperature at which the heating process should stop.

state
An enumeration that represents the current state of the heating process. It can take on one of the following values:

UNDER_MIN: the temperature is below the minimum threshold
HEATING_UP: the temperature is rising
OVER_MAX: the temperature is above the maximum threshold
COOLING_OFF: the device is cooling off
License
This code is licensed under the MIT License.
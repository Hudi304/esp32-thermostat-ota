#ifndef TEMPERATURE_CONTROL_H
#define TEMPERATURE_CONTROL_H

#include <DallasTemperature.h>
#include "variables.h"


void check_temp(float &ambient_t_C, DallasTemperature &sensors);

void update_state(float ambient_t_C, float start_at_temp_C, float stop_at_temp_C);

#endif // TEMPERATURE_CONTROL_H
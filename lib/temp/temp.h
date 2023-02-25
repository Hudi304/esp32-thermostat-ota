#ifndef TEMPERATURE_CONTROL_H
#define TEMPERATURE_CONTROL_H

#include <DallasTemperature.h>
#include "variables.h"

#define CHECK_TEMP_EVERY 5

void check_temp(float &ambient_t_C, DallasTemperature &sensors);

#endif // TEMPERATURE_CONTROL_H
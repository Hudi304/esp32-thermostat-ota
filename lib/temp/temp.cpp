#include "temp.h"
#include "common.h"

void update_state(float ambient_t_C, float min_temp, float max_temp)
{
  switch (state)
  {
  case COOLING_OFF:
    if (ambient_t_C < min_temp)
    {
      state = HEATING_UP;
      digitalWrite(RELAY_PIN, true);
      digitalWrite(LED_BUILTIN, true);
    }
    break;

  case HEATING_UP:
    if (ambient_t_C > max_temp)
    {
      state = COOLING_OFF;
      digitalWrite(RELAY_PIN, false);
      digitalWrite(LED_BUILTIN, false);
    }
    break;

  default:
    break;
  }
}
/*
 * Check the current temperature reading from the DallasTemperature sensor and adjust the
 * state of the heater accordingly. The function runs periodically based on the CHECK_TEMP_EVERY
 * interval defined in variables.h.
 *
 * Arguments:
 *     ambient_t_C: a reference to the ambient temperature variable to be updated by the function
 *     sensors: a reference to the DallasTemperature sensor object used to read temperature
 *
 * Returns:
 *     None
 */
void check_temp(float &ambient_t_C, DallasTemperature &sensors)
{
  curr_check_no = sec_since_on / CHECK_TEMP_EVERY;
  if (curr_check_no == prev_check_no)
  {
    return;
  }

  sensors.requestTemperatures();
  ambient_t_C = sensors.getTempCByIndex(0);
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);
  debugPrint("here");
  prev_check_no = curr_check_no;
}

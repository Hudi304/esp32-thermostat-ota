#include "temp.h"
#include "common.h"

// TODO test this, there is a flicker on first boot
// lower then min => HEAT UP
void init_state_machine(DallasTemperature &sensors)
{
  sensors.requestTemperatures();
  ambient_t_C = sensors.getTempCByIndex(0);
  if (ambient_t_C < min_temp)
  {
    state = HEATING_UP;
    heater_pin_state = LOW;
    digitalWrite(RELAY_PIN, heater_pin_state);
  }
  // higher then max => COOL_DOWN
  else if (ambient_t_C > max_temp)
  {
    heater_pin_state = HIGH;
    digitalWrite(RELAY_PIN, heater_pin_state);
    state = COOLING_OFF;
  }
  // between => COOL_DOWN
  else
  {
    heater_pin_state = HIGH;
    digitalWrite(RELAY_PIN, heater_pin_state);
    state = COOLING_OFF;
  }
}

void heat_up()
{
  state = HEATING_UP;
  status_led_state = HIGH;
  heater_pin_state = LOW;
  digitalWrite(LED_BUILTIN, status_led_state);
  digitalWrite(RELAY_PIN, heater_pin_state);
}

void cool_off()
{
  state = COOLING_OFF;
  status_led_state = LOW;
  heater_pin_state = HIGH;
  digitalWrite(LED_BUILTIN, status_led_state);
  digitalWrite(RELAY_PIN, heater_pin_state);
}

void update_state(float ambient, float min_temp, float max_temp)
{
  switch (state)
  {
  case COOLING_OFF:
    if (ambient < min_temp)
    {
      heat_up();
    }
    break;

  case HEATING_UP:
    if (ambient > max_temp)
    {
      cool_off();
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
// TODO change this logic so that this is called more then once every second
void check_temp(float &ambient_t_C, DallasTemperature &sensors)
{
  curr_check_no = sec_since_on / CHECK_TEMP_EVERY;
  bool should_not_read_sensors = curr_check_no == prev_check_no;

  if (should_not_read_sensors)
  {
    return;
  }

  sensors.requestTemperatures();
  ambient_t_C = sensors.getTempCByIndex(0);
  update_state(ambient_t_C, min_temp, max_temp);
  debugPrint("here");
  prev_check_no = curr_check_no;
}

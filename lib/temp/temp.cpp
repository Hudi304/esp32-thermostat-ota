#include "temp.h"

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
void update_state(float ambient_t_C, float start_at_temp_C, float stop_at_temp_C)
{
    switch (state)
    {
    case COOLING_OFF:
        if (ambient_t_C < start_at_temp_C)
        {
            state = HEATING_UP;
            digitalWrite(RELAY_PIN, true);
            digitalWrite(LED_BUILTIN, true);
            Serial.println("cooling off");
        }
        break;

    case HEATING_UP:
        if (ambient_t_C > stop_at_temp_C)
        {
            state = COOLING_OFF;
            digitalWrite(RELAY_PIN, false);
            digitalWrite(LED_BUILTIN, false);
            Serial.println("heating up");
        }
        break;

    default:
        break;
    }
}

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

    Serial.print(ambient_t_C);
    Serial.println("ºC");

    Serial.print(sec_since_on);
    Serial.println(" seconds since on");

    prev_check_no = curr_check_no;
}

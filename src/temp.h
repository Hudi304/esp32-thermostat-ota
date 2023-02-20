#define CHECK_TEMP_EVERY 5

void check_temp(float &ambient_t_C, DallasTemperature &sensors)
{
    curr_check_no = sec_since_on / CHECK_TEMP_EVERY;
    if (curr_check_no != prev_check_no)
    {
        sensors.requestTemperatures();
        ambient_t_C = sensors.getTempCByIndex(0);

        switch (state)
        {
        case COOLING_OFF:
            if (ambient_t_C < start_at_temp_C)
            {
                state = UNDER_MIN;
            }
            Serial.println("cooling off");
            break;

        case UNDER_MIN:
            digitalWrite(RELAY_PIN, true);
            digitalWrite(LED_BUILTIN, true);
            state = HEATING_UP;
            Serial.println("under-min");
            break;

        case HEATING_UP:
            if (ambient_t_C > stop_at_temp_C)
            {
                state = OVER_MAX;
            }
            Serial.println("heating-up");
            break;

        case OVER_MAX:
            digitalWrite(RELAY_PIN, false);
            digitalWrite(LED_BUILTIN, false);
            Serial.println("over-max");
            state = COOLING_OFF;
            break;
        default:
            break;
        }

        Serial.print(ambient_t_C);
        Serial.println("ºC");

        Serial.print(sec_since_on);
        Serial.println(" seconds since on");

        prev_check_no = curr_check_no;
    }
}
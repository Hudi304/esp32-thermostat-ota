#include "handlers.h"

String get_status_response_builder()
{
    String response = String("");
    response.concat("start_temp:");
    response.concat(min_temp);
    response.concat("|");

    response.concat("ambient_temp:");
    response.concat(ambient_t_C);
    response.concat("|");

    response.concat("stop_temp:");
    response.concat(max_temp);
    response.concat("|");

    response.concat("heater_pin_state:");
    response.concat(heater_pin_state);

    response.concat("state:");

    if (state == HEATING_UP)
    {
        response.concat("HEATING_UP");
    }
    else
    {
        response.concat("COOLING_OFF");
    }

    return response;
}

void get_status_handler(Request &req, Response &res)
{
    String resp_body = get_status_response_builder();
    res.print(resp_body);
}

void put_start_temp(Request &req, Response &res)
{
    String request_str = req.readString();
    float to_float = request_str.toFloat();
    min_temp = to_float;
}

void put_stop_temp(Request &req, Response &res)
{
    String request_str = req.readString();
    float to_float = request_str.toFloat();
    max_temp = to_float;
}

void get_led_status(Request &req, Response &res)
{

    heater_pin_state = !heater_pin_state;

    // digitalWrite(RELAY_PIN, heater_pin_state);

    res.print(heater_pin_state);
}

void put_led(Request &req, Response &res)
{
    bool ledOn = (req.read() != '0');
    res.print(ledOn);
}

void get_complete_status(Request &req, Response &res)
{
    String sec_since_on_str = String(sec_since_on);
}

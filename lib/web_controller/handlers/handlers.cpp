#include "handlers.h"

void get_status_handler(Request &req, Response &res)
{
    String response = String("");
    response.concat("start_temp:");
    response.concat(start_at_temp_C);
    response.concat("|");

    response.concat("ambient_temp:");
    response.concat(ambient_t_C);
    response.concat("|");

    response.concat("stop_temp:");
    response.concat(stop_at_temp_C);
    response.concat("|");

    response.concat("heater_status:");
    response.concat(board_status_led);

    String resp_body = get_status_response_builder();

    res.print(resp_body);
}

String get_status_response_builder()
{
    String response = String("");
    response.concat("start_temp:");
    response.concat(start_at_temp_C);
    response.concat("|");

    response.concat("ambient_temp:");
    response.concat(ambient_t_C);
    response.concat("|");

    response.concat("stop_temp:");
    response.concat(stop_at_temp_C);
    response.concat("|");

    response.concat("heater_status:");
    response.concat(board_status_led);

    return response;
}
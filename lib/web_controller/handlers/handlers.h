#ifndef WEB_CONTROLLER_HANDLERS
#define WEB_CONTROLLER_HANDLERS

#include <aWOT.h>
#include "variables.h"

String get_status_response_builder();

void get_status_handler(Request &req, Response &res);

void put_stop_temp(Request &req, Response &res);

void put_start_temp(Request &req, Response &res);

void get_led_status(Request &req, Response &res);

void put_led(Request &req, Response &res);

void get_complete_status(Request &req, Response &res);

#endif

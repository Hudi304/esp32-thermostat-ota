#ifndef WEB_CONTROLLER
#define WEB_CONTROLLER

#include <aWOT.h>
#include "variables.h"

void readLed(Request &req, Response &res);

void updateLed(Request &req, Response &res);

void get_status(Request &req, Response &res);

void update_start_temp(Request &req, Response &res);

void update_stop_temp(Request &req, Response &res);

void configure_app(Application &app);

#endif

#ifndef WEB_CONTROLLER_HANDLERS
#define WEB_CONTROLLER_HANDLERS

#include <aWOT.h>
#include "variables.h"

void get_status_handler(Request &req, Response &res);

String get_status_response_builder();


#endif

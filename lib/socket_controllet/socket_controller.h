#ifndef WEB_SOCKET_SERVER
#define WEB_SOCKET_SERVER

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "variables.h"
#include "handlers/handlers.h"

void initWebSocket(AsyncWebSocket *web_socket, AsyncWebServer *async_web_server);

#endif
#ifndef WEB_SOCKET_MESSAGE_HANDLERS
#define WEB_SOCKET_MESSAGE_HANDLERS

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "variables.h"
#include "common.h"

void on_disconnect(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len);

void on_pong(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len);

void on_error(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len);

void on_connect(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len);

void on_message(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len);

#endif
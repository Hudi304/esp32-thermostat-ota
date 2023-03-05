#include "socket_controller.h"

void onEvent(AsyncWebSocket *socket, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len)
{

  debug("on Event");
  switch (type)
  {
  case WS_EVT_CONNECT:
    return on_connect(socket, client, arg, data, len);

  case WS_EVT_DATA:
    return on_message(socket, client, arg, data, len);

  case WS_EVT_PONG:
    return on_pong(socket, client, arg, data, len);

  case WS_EVT_DISCONNECT:
    return on_disconnect(socket, client, arg, data, len);

  case WS_EVT_ERROR:
    return on_error(socket, client, arg, data, len);
  }
}

void initWebSocket(AsyncWebSocket *web_socket, AsyncWebServer *async_web_server)
{

  debug("initWebSocket");
  web_socket->onEvent(onEvent);
  async_web_server->addHandler(web_socket);
}

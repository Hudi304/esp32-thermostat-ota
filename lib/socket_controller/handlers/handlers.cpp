#include "handlers.h"

void notifyClientsStr(AsyncWebSocket *web_socket, String msg)
{
  web_socket->textAll(msg);
}

void on_disconnect(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len)
{
  debug("on_disconnect \n");
}

void on_pong(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len)
{
  debug("on_pong \n");
}

void on_error(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len)
{
  debug("on_err \n");
}

void on_connect(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len)
{
  debug("on_connect \n");
}

boolean isValidMessage(AwsFrameInfo *info, size_t len)
{
  return info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT;
}

void on_message(AsyncWebSocket *socket, AsyncWebSocketClient *client, void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (isValidMessage(info, len))
  {
    debug("VALID WS MESSAGE \n");

    data[len] = 0;
    String dataString = String((const char *)data);
    if (strcmp((char *)data, "toggle") == 0)
    {
    }

    if (strcmp((char *)data, "A") == 0)
    {
      // Serial.print('A');
      notifyClientsStr(socket, "UART : A");
    }

    if (strcmp((char *)data, "R") == 0)
    {
    }
    else
    {
    }
  }
  else
  {
    debug("NOT A VALID MESSAGE \n");
  }
}

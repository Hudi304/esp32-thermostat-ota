#include <Arduino.h>
#include <aWOT.h>
#include <OneWire.h>
#include <WiFi.h>
#include <DallasTemperature.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>
#include <stdio.h>
#include <WiFiUdp.h>

#include "common.h"
#include "variables.h"
#include "temp.h"
#include "web_controller.h"
#include "mDNS.h"
#include "ota.h"
#include "socket_controller.h"

// Import required libraries
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "credentials.h"
#include "index.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
// // does this do anything?
WiFiServer server(81);
Application app;

bool ledState = 0;
const int ledPin = 2;

// Create AsyncWebServer object on port 81
AsyncWebServer async_web_server(80);
AsyncWebSocket ws("/ws");


void notifyClients()
{
  ws.textAll(String(ledState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {
    data[len] = 0;
    if (strcmp((char *)data, "toggle") == 0)
    {
      ledState = !ledState;
      notifyClients();
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    handleWebSocketMessage(arg, data, len);
    break; // Route for root / web page
    // async_web_server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    // { request->send_P(200, "text/html", index_html, processor); });

  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void initWebSocket()
{
  ws.onEvent(onEvent);
  async_web_server.addHandler(&ws);
}

String processor(const String &var)
{
  Serial.println(var);
  if (var == "STATE")
  {
    if (ledState)
    {
      return "ON";
    }
    else
    {
      return "OFF";
    }
  }
  return String();
}

void setup()
{
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 1);
  Serial.begin(115200);
  // wifi connection
  connect_to_wifi(WIFI_SSID, WIFI_PASSWORD);

  // server_setup
  configure_server(app);

  sensors.begin();
  server.begin();

  delay(100);

  init_state_machine(sensors);
  initWebSocket();
  // Route for root / web page
  async_web_server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                      { request->send_P(200, "text/html", index_html, processor); });

  // Start server
  async_web_server.begin();
}

void loop()
{
  ws.cleanupClients();
  compute_seconds_since_on();
  process_web_client(server, app);
  check_temp(ambient_t_C, sensors);

  digitalWrite(ledPin, ledState);
}
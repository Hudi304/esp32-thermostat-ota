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

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "credentials.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
// does this do anything?
WiFiServer server(80);
Application app;

// we might not need the other application at all
AsyncWebServer async_server(81);
AsyncWebSocket ws("/ws");

void setup()
{
  // Pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  // wifi connection
  connect_to_wifi(WIFI_SSID, WIFI_PASSWORD);
  // server_setup
  configure_server(app);

  server.begin();
  sensors.begin();

  // you can find the app at http://thermostat.local
  set_up_mDNS("thermostat");
  // sets up a simple over the air (OTA) config
  set_up_OTA("thermostat");

  delay(100);

  init_state_machine(sensors);

  initWebSocket(&ws, &async_server);
}

void loop()
{
  compute_seconds_since_on();
  process_web_client(server, app);
  check_temp(ambient_t_C, sensors);
  ArduinoOTA.handle();
}
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

// #define WIFI_SSID "TechQuarter"
// #define WIFI_PASSWORD "!techP455"

// #define WIFI_SSID "Redmi"
// #define WIFI_PASSWORD "12345678"

#define WIFI_SSID "UPC555516D"
#define WIFI_PASSWORD "RshmdceznMv6"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
WiFiServer server(80);
Application app;

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  connect_to_wifi(WIFI_SSID, WIFI_PASSWORD);
  configure_app(app);
  server.begin();
  sensors.begin();

  set_up_mDNS("thermostat");

  setup_OTA();
}
void loop()
{
  //! Do not delete
  millis_sec();
  process_web_client(server, app);
  check_temp(ambient_t_C, sensors);
  ArduinoOTA.handle();
}
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

#include "credentials.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
WiFiServer server(80);
Application app;

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

  // makes the IP of the device irrelevant
  // you can find the app at http://thermostat.local
  set_up_mDNS("thermostat");

  // sets up a simple over the air (OTA) config
  set_up_OTA();

  delay(100);

  sensors.requestTemperatures();
  ambient_t_C = sensors.getTempCByIndex(0);

  // TODO test this, there is a flicker on first boot

  // lower then min => HEAT UP
  if (ambient_t_C < min_temp)
  {
    state = HEATING_UP;
    heater_pin_state = LOW;
    // TODO make a class that can be instantiated
    // in the variables.cpp file
    // that has as methods, the pinNo, negativeLogic boolean
    // setActualHigh
    // setActualLow
    digitalWrite(RELAY_PIN, heater_pin_state);
  }
  // higher then max => COOL_DOWN
  else if (ambient_t_C > max_temp)
  {
    heater_pin_state = HIGH;
    digitalWrite(RELAY_PIN, heater_pin_state);
    state = COOLING_OFF;
  }
  // between => COOL_DOWN
  else
  {
    heater_pin_state = HIGH;
    digitalWrite(RELAY_PIN, heater_pin_state);
    state = COOLING_OFF;
  }
}
void loop()
{
  compute_seconds_since_on();
  process_web_client(server, app);
  check_temp(ambient_t_C, sensors);
  ArduinoOTA.handle();
}
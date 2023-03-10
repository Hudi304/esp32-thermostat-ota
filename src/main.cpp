#include <aWOT.h>
#include <OneWire.h>
#include <WiFi.h>
#include <DallasTemperature.h>

#include <ESPmDNS.h>

#include <stdio.h>

#include "variables.h"
#include "temp.h"
#include "controller.h"
#include "web_server_utils.h"

#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// #define WIFI_SSID "TechQuarter"
// #define WIFI_PASSWORD "!techP455"

#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "12345678"

// #define WIFI_SSID "UPC555516D"
// #define WIFI_PASSWORD "RshmdceznMv6"

#define ONE_WIRE_BUS 4 // as we connected it on D2 the GPIO of it is 4 (Check NodeMCU pinout)

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

  // if (!MDNS.begin("thermostat"))
  // {
  //   Serial.println("Error starting mDNS");
  //   return;
  // }

  MDNS.begin("esp32");
  MDNS.addService("_http", "_tcp", 80);
  MDNS.addServiceTxt("_http", "_tcp", "board", "ESP32");

  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  // ArduinoOTA.setHostname("myesp32");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.setHostname(server_url);

  ArduinoOTA
      .onStart([]()
               {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type); })
      .onEnd([]()
             { Serial.println("\nEnd"); })
      .onProgress([](unsigned int progress, unsigned int total)
                  { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); })
      .onError([](ota_error_t error)
               {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed"); });

  ArduinoOTA.begin();
}
void loop()
{
  //! Do not delete
  millis_sec();
  process_web_client(server, app);
  check_temp(ambient_t_C, sensors);
  ArduinoOTA.handle();
}
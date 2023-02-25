#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H

#include <Arduino.h>
#include "variables.h"
#include <WiFi.h>
#include <aWOT.h>

void debugPrint(const char *msg);
void connect_to_wifi(const char *WIFI_SSID, const char *WIFI_PASSWORD);
void process_web_client(WiFiServer &server, Application &app);
void millis_sec();

#endif
#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H

#include <Arduino.h>
#include "variables.h"
#include <WiFi.h>
#include <aWOT.h>

void debugPrint(const char *msg);
void connect_to_wifi(const char *WIFI_SSID, const char *WIFI_PASSWORD);
void process_web_client(WiFiServer &server, Application &app);
void compute_seconds_since_on();

// TODO it might be a good idea for this to return void
// should have a smaller overhead in "production"
size_t debug(const char *msg);
size_t debug(const String &s);
size_t debug(char c);

#endif
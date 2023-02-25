#include "mDNS.h"

void set_up_mDNS(const char *hostName)
{
    if (!MDNS.begin("thermostat"))
    {
        Serial.println("Error starting mDNS");
        return;
    }

    MDNS.begin("esp32");
    MDNS.addService("_http", "_tcp", 80);
    MDNS.addServiceTxt("_http", "_tcp", "board", "ESP32");
}
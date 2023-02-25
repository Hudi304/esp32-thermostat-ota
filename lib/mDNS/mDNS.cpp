#include "mDNS.h"

void set_up_mDNS(const char *hostName)
{
    if (!MDNS.begin(hostName))
    {
        Serial.println("Error starting mDNS");
        return;
    }

    MDNS.addService("_http", "_tcp", 80);
    MDNS.addServiceTxt("_http", "_tcp", "board", "ESP32");
}
#include "common.h"

void debugPrint(const char *msg)
{
#ifndef DEBUG_MODE
    Serial.print(msg);
#endif
}

void connect_to_wifi(const char *WIFI_SSID, const char *WIFI_PASSWORD)
{
    Serial.print(".\n");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".\n");
    }

    Serial.println(WiFi.localIP());
}

void process_web_client(WiFiServer &server, Application &app)
{
    WiFiClient client = server.available();
    if (client.connected())
    {
        app.process(&client);
    }
}

void millis_sec()
{
    curr_millis = millis();
    unsigned long elapsed_secs = 0;

    if (curr_millis < prev_millis)
    {
        // overflow
        elapsed_secs = (MAX_LONG - prev_millis + curr_millis) / 1000;
    }
    else
    {
        elapsed_secs = (curr_millis - prev_millis) / 1000;
    }

    if (elapsed_secs > 0)
    {
        sec_since_on += elapsed_secs;
        prev_millis = curr_millis;
    }
}

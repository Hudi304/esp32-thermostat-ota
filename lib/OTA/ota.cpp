#include "ota.h"

void on_end()
{
  Serial.println("\nEnd");
  ESP.restart();
}

void on_start()
{
  String type;
  if (ArduinoOTA.getCommand() == U_FLASH)
    type = "sketch";
  else // U_SPIFFS
    type = "filesystem";

  // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
  Serial.println("Start updating " + type);
}

void on_progress(unsigned int progress, unsigned int total)
{
  Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
}

void on_error(ota_error_t error)
{
  switch (error)
  {
  case OTA_AUTH_ERROR:
    Serial.println("Auth Failed");
    break;
  case OTA_BEGIN_ERROR:
    Serial.println("Begin Failed");
    break;
  case OTA_CONNECT_ERROR:
    Serial.println("Connect Failed");
    break;
  case OTA_RECEIVE_ERROR:
    Serial.println("Receive Failed");
    break;
  case OTA_END_ERROR:
    Serial.println("End Failed");
    break;
  default:
    Serial.printf("Error[%u]: ", error);
    break;
  }
}

void set_up_OTA(const char *hostName)
{

  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  // ArduinoOTA.setHostname("server_url");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.setHostname(hostName);

  ArduinoOTA
      .onStart(on_start)
      .onEnd(on_end)
      .onProgress(on_progress)
      .onError(on_error);

  ArduinoOTA.begin();
}

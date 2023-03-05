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
  // set_up_mDNS("thermostat_dev");
  // sets up a simple over the air (OTA) config
  // set_up_OTA("thermostat_dev");

  delay(100);

  // initWebSocket(&ws, &async_server);
}

void loop()
{
  compute_seconds_since_on();
  // process_web_client(server, app);
  // check_temp(ambient_t_C, sensors);
  // ArduinoOTA.handle();
  ws.cleanupClients();
}
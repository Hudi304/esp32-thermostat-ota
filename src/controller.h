#include "StaticFiles.h"
#include "variables.h"


void readLed(Request &req, Response &res)
{
    res.print(ledOn);
}

void updateLed(Request &req, Response &res)
{
    bool ledOn = (req.read() != '0');
    // digitalWrite(LED_BUILTIN, ledOn);
    res.print(ledOn);
}

void get_status(Request &req, Response &res)
{
    String response = String("");
    response.concat("start_temp:");
    response.concat(start_at_temp_C);
    response.concat("|");

    response.concat("ambient_temp:");
    response.concat(ambient_t_C);
    response.concat("|");

    response.concat("stop_temp:");
    response.concat(stop_at_temp_C);
    response.concat("|");

    response.concat("heater_status:");
    response.concat(ledOn);

    res.print(response);
}

void update_start_temp(Request &req, Response &res)
{
    String request_str = req.readString();
    Serial.print("request_str : ");
    Serial.println(request_str);
    float to_float = request_str.toFloat();
    Serial.print("to_float : ");
    Serial.println(to_float);
    start_at_temp_C = to_float;
}

void update_stop_temp(Request &req, Response &res)
{
    String request_str = req.readString();
    Serial.print("request_str : ");
    Serial.println(request_str);
    float to_float = request_str.toFloat();
    Serial.print("to_float : ");
    Serial.println(to_float);
    stop_at_temp_C = to_float;
}

void configure_app(Application &app)
{
    app.get("/led", &readLed);
    app.put("/led", &updateLed);

    app.get("/status", &get_status);
    app.put("/start-temp", &update_start_temp);
    app.put("/stop-temp", &update_stop_temp);

    app.use(staticFiles());
}

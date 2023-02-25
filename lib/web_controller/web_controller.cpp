#include "web_controller.h"

void configure_server(Application &app)
{
    app.get("/led", &get_led_status);
    app.put("/led", &put_led);

    app.get("/status", &get_status_handler);

    app.put("/start-temp", &put_start_temp);
    app.put("/stop-temp", &put_stop_temp);

    app.get("/complete-status", &get_complete_status);

    app.use(staticFiles());
}
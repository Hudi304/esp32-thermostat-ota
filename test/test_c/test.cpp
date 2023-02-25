#include "Arduino.h"
#include <unity.h>
#include "temp.h"
#include "temp_controller/temp_controller_tests.h"
#include "web_hndl/web_hndl_tests.h"

void setup()
{
  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_get_status_response_builder);
  RUN_TEST(test_get_status_response_builder_with_negative_temperatures);
  RUN_TEST(test_get_status_response_builder_with_zero_temperatures);
  RUN_TEST(test_get_status_response_builder_with_decimal_rounding);

  RUN_TEST(test_update_state_cooling_off_ambient_above_max);
  RUN_TEST(test_update_state_cooling_off_ambient_below_min);
  RUN_TEST(test_update_state_cooling_off_ambient_within_range);
  RUN_TEST(test_update_state_heating_up_ambient_above_max);
  RUN_TEST(test_update_state_heating_up_ambient_below_min);
  RUN_TEST(test_update_state_heating_up_ambient_within_range);
}

// you can leave this empty
// but you can not remove it
void loop()
{
  UNITY_END(); // stop unit testing
}
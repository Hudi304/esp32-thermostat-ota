#include "web_hndl_tests.h"

void test_get_status_response_builder()
{
  // Arrange
  min_temp = 20.0;
  ambient_t_C = 23.5;
  max_temp = 25.0;
  board_status_led = HIGH;
  String expected = "start_temp:20.00|ambient_temp:23.50|stop_temp:25.00|heater_status:1";

  // Act
  String response = get_status_response_builder();

  // Assert
  TEST_ASSERT_EQUAL_STRING(expected.c_str(), response.c_str());
}

void test_get_status_response_builder_with_negative_temperatures()
{
  // Arrange
  min_temp = -10.0;
  ambient_t_C = -5.5;
  max_temp = 0.0;
  board_status_led = LOW;
  String expected = "start_temp:-10.00|ambient_temp:-5.50|stop_temp:0.00|heater_status:0";

  // Act
  String response = get_status_response_builder();

  // Assert
  TEST_ASSERT_EQUAL_STRING(expected.c_str(), response.c_str());
}

void test_get_status_response_builder_with_zero_temperatures()
{
  // Arrange
  min_temp = 0.0;
  ambient_t_C = 0.0;
  max_temp = 0.0;
  board_status_led = HIGH;
  String expected = "start_temp:0.00|ambient_temp:0.00|stop_temp:0.00|heater_status:1";

  // Act
  String response = get_status_response_builder();

  // Assert
  TEST_ASSERT_EQUAL_STRING(expected.c_str(), response.c_str());
}

void test_get_status_response_builder_with_decimal_rounding()
{
  // Arrange
  min_temp = 10.12345;
  ambient_t_C = 15.6789;
  max_temp = 20.4321;
  board_status_led = HIGH;
  String expected = "start_temp:10.12|ambient_temp:15.68|stop_temp:20.43|heater_status:1";

  // Act
  String response = get_status_response_builder();

  // Assert
  TEST_ASSERT_EQUAL_STRING(expected.c_str(), response.c_str());
}

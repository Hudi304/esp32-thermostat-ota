#include <Arduino.h>
#include <unity.h>
#include "temp.h"

void setUp(void)
{
  // set stuff up here
  // setUpfunction is called before the invocation of each test method
}

void tearDown(void)
{
  // clean stuff up here
  // tearDown function is called after the invocation of each test method
}

void test_update_state(void)
{
  // Test cooling off to heating up
  state = COOLING_OFF;
  update_state(20.0, 22.0, 26.0);
  TEST_ASSERT_EQUAL(HEATING_UP, state);

  // Test heating up to cooling off
  state = HEATING_UP;
  update_state(27.0, 22.0, 26.0);
  TEST_ASSERT_EQUAL(COOLING_OFF, state);

  // Test no state change
  state = COOLING_OFF;
  update_state(25.0, 22.0, 26.0);
  TEST_ASSERT_EQUAL(COOLING_OFF, state);
}

void test_update_state_cooling_off_ambient_below_min()
{
  // Arrange
  float ambient_t_C = -10.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = COOLING_OFF;

  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);

  // Assert
  TEST_ASSERT_EQUAL(HEATING_UP, state);
}

void test_update_state_cooling_off_ambient_above_max()
{
  // Arrange
  float ambient_t_C = 40.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = COOLING_OFF;

  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);

  // Assert
  TEST_ASSERT_EQUAL(COOLING_OFF, state);
}

void test_update_state_cooling_off_ambient_within_range()
{
  // Arrange
  float ambient_t_C = 25.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = COOLING_OFF;

  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);

  // Assert
  TEST_ASSERT_EQUAL(COOLING_OFF, state);
}

void test_update_state_heating_up_ambient_below_min()
{
  // Arrange
  float ambient_t_C = -10.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = HEATING_UP;

  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);

  // Assert
  TEST_ASSERT_EQUAL(HEATING_UP, state);
}

void test_update_state_heating_up_ambient_above_max()
{
  // Arrange
  float ambient_t_C = 40.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = HEATING_UP;

  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);

  // Assert
  TEST_ASSERT_EQUAL(COOLING_OFF, state);
}

void test_update_state_heating_up_ambient_within_range()
{
  // Arrange
  float ambient_t_C = 25.0f;
  float start_at_temp_C = 20.0f;
  float stop_at_temp_C = 30.0f;
  state = HEATING_UP;
  // Act
  update_state(ambient_t_C, start_at_temp_C, stop_at_temp_C);
  // Assert
  TEST_ASSERT_EQUAL(HEATING_UP, state);
}

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  UNITY_BEGIN(); // IMPORTANT LINE!
  // RUN_TEST(test_update_state);
  RUN_TEST(test_update_state_cooling_off_ambient_above_max);
  RUN_TEST(test_update_state_cooling_off_ambient_below_min);
  RUN_TEST(test_update_state_cooling_off_ambient_within_range);
  RUN_TEST(test_update_state_heating_up_ambient_above_max);
  RUN_TEST(test_update_state_heating_up_ambient_below_min);
  RUN_TEST(test_update_state_heating_up_ambient_within_range);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

// you can leave this empty
// but you can not remove it
void loop()
{
  UNITY_END(); // stop unit testing
}
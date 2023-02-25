#include <Arduino.h>
#include <unity.h>
#define LED_BUILTIN 2

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

void test_led_builtin_pin_number(void)
{
  TEST_ASSERT_EQUAL(2, LED_BUILTIN);
}

void test_led_state_high(void)
{
  digitalWrite(LED_BUILTIN, HIGH);
  TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void)
{
  digitalWrite(LED_BUILTIN, LOW);
  TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_led_builtin_pin_number);
  UNITY_END(); // stop unit testing
}

uint8_t i = 0;
uint8_t max_blinks = 5;

// you can leave this empty
// but you can not remove it
void loop()
{
  UNITY_END(); // stop unit testing
}
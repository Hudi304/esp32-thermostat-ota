#include "loop_tests.h"

void test_compute_seconds_since_on_overflow()
{
    sec_since_on = 0;

    // set prev_millis to some large value

    prev_millis = MAX_LONG - 5000;

    // set curr_millis to a value less than prev_millis
    curr_millis = 2000;
    unsigned long expected_secs_since_on = (MAX_LONG - prev_millis + curr_millis) / 1000;

    // call the function
    compute_seconds_since_on();

    // check that sec_since_on has been updated correctly
    TEST_ASSERT_EQUAL(expected_secs_since_on, sec_since_on);

    // check that prev_millis has been updated
    // TEST_ASSERT_EQUAL(curr_millis, prev_millis);
}

void test_compute_seconds_since_on_no_overflow()
{

    sec_since_on = 0;
    // set prev_millis to some value
    prev_millis = 1000;

    // set curr_millis to a value greater than prev_millis
    curr_millis = 2000;

    // call the function
    compute_seconds_since_on();

    // check that sec_since_on has been updated
    TEST_ASSERT_EQUAL(1, sec_since_on);

    // check that prev_millis has been updated
    // TEST_ASSERT_EQUAL(curr_millis, prev_millis);
}
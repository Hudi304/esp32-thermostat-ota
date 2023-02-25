
#ifndef __TEMP_CONTROLLER_TESTS__
#define __TEMP_CONTROLLER_TESTS__

void test_update_state_cooling_off_ambient_below_min();

void test_update_state_cooling_off_ambient_above_max();

void test_update_state_cooling_off_ambient_within_range();

void test_update_state_heating_up_ambient_below_min();

void test_update_state_heating_up_ambient_above_max();

void test_update_state_heating_up_ambient_within_range();

#endif

#ifndef __WEB_CONTROLLER_TESTS__
#define __WEB_CONTROLLER_TESTS__

#include "variables.h"

void test_get_status_response_builder();

void test_get_status_response_builder_with_negative_temperatures();

void test_get_status_response_builder_with_zero_temperatures();

void test_get_status_response_builder_with_decimal_rounding();

#endif
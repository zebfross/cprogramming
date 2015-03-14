#include "unity.h"
#include "unity_fixture.h"
#include <setjmp.h>
#include <stdio.h>

TEST_GROUP_RUNNER(Exercises)
{
	RUN_TEST_CASE(Exercises, test_day_of_year);
	RUN_TEST_CASE(Exercises, test_day_of_year_leap);
	RUN_TEST_CASE(Exercises, test_day_of_year_bad_input);
	RUN_TEST_CASE(Exercises, test_month_day);
	RUN_TEST_CASE(Exercises, test_month_day_leap);
	RUN_TEST_CASE(Exercises, test_month_day_bad_input);

}


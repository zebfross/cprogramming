#include "unity.h"
#include "unity_fixture.h"
#include <setjmp.h>
#include <stdio.h>

TEST_GROUP_RUNNER(ExprCode)
{
	RUN_TEST_CASE(ExprCode, test_no_args);
	RUN_TEST_CASE(ExprCode, test_add);
	RUN_TEST_CASE(ExprCode, test_sub);
	RUN_TEST_CASE(ExprCode, test_mult);
	RUN_TEST_CASE(ExprCode, test_div);
}


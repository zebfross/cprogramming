#include "unity.h"
#include "unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(ExprCode);
	RUN_TEST_GROUP(Exercises);
}

int main(int argc, const char * argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}

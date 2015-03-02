#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

char MessageBuffer[50];

extern void setUp(void);
extern void tearDown(void);

extern void test_day_of_year(void);
extern void test_day_of_year_leap(void);
extern void test_day_of_year_bad_input(void);
extern void test_month_day(void);
extern void test_month_day_leap(void);
extern void test_month_day_bad_input(void);

void resetTest(void);
void resetTest(void) {
	tearDown();
	setUp();
}

int main(void) {
	UnityBegin("test/exercises_test.c");

	RUN_TEST(test_day_of_year);
	RUN_TEST(test_day_of_year_leap);
	RUN_TEST(test_day_of_year_bad_input);
	RUN_TEST(test_month_day);
	RUN_TEST(test_month_day_leap);
	RUN_TEST(test_month_day_bad_input);

	UnityEnd();
	return 0;
}

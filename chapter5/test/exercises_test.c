#include "exercises.h"
#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_day_of_year(void) {
	int day;
	day = day_of_year(2010, 5, 27);
	TEST_ASSERT_EQUAL_INT(147, day);
}

void test_day_of_year_leap(void) {
	int day;
	day = day_of_year(2012, 5, 27);
	TEST_ASSERT_EQUAL_INT(148, day);
}

void test_day_of_year_bad_input(void) {
	int day;
	day = day_of_year(2010, 5, 300);
	TEST_ASSERT_EQUAL_INT(-1, day);
}

void test_month_day(void) {
	int month, day;
	month_day(2010, 72, &month, &day);
	TEST_ASSERT_EQUAL_INT(3, month);
	TEST_ASSERT_EQUAL_INT(13, day);
}

void test_month_day_leap(void) {
	int month, day;
	month_day(2012, 72, &month, &day);
	TEST_ASSERT_EQUAL_INT(3, month);
	TEST_ASSERT_EQUAL_INT(12, day);
}

void test_month_day_bad_input(void) {
	int month, day;
	month_day(2010, 726, &month, &day);
	TEST_ASSERT_EQUAL_INT(-1, month);
	TEST_ASSERT_EQUAL_INT(-1, day);
}

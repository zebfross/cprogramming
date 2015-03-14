#include "exercises.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Exercises);

TEST_SETUP(Exercises)
{

}

TEST_TEAR_DOWN(Exercises)
{

}

TEST(Exercises, test_day_of_year) {
	int day;
	day = day_of_year(2010, 5, 27);
	TEST_ASSERT_EQUAL_INT(147, day);
}

TEST(Exercises, test_day_of_year_leap) {
	int day;
	day = day_of_year(2012, 5, 27);
	TEST_ASSERT_EQUAL_INT(148, day);
}

TEST(Exercises, test_day_of_year_bad_input) {
	int day;
	day = day_of_year(2010, 5, 300);
	TEST_ASSERT_EQUAL_INT(-1, day);
}

TEST(Exercises, test_month_day) {
	int month, day;
	month_day(2010, 72, &month, &day);
	TEST_ASSERT_EQUAL_INT(3, month);
	TEST_ASSERT_EQUAL_INT(13, day);
}

TEST(Exercises, test_month_day_leap) {
	int month, day;
	month_day(2012, 72, &month, &day);
	TEST_ASSERT_EQUAL_INT(3, month);
	TEST_ASSERT_EQUAL_INT(12, day);
}

TEST(Exercises, test_month_day_bad_input) {
	int month, day;
	month_day(2010, 726, &month, &day);
	TEST_ASSERT_EQUAL_INT(-1, month);
	TEST_ASSERT_EQUAL_INT(-1, day);
}

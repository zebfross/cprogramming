#include "expr.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ExprCode);

TEST_SETUP(ExprCode) 
{

}

TEST_TEAR_DOWN(ExprCode) 
{

}


TEST(ExprCode, test_no_args) {
	int c;
	double res;
	char *argv[] = {"expr.exe"};
	c = 1;
	res = expr(c, argv);	
	TEST_ASSERT_EQUAL_FLOAT(0, res);
}

TEST(ExprCode, test_add) {

	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "600", "+"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(1100, res);
}

TEST(ExprCode, test_sub) {


	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "600", "-"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(-100, res);
}

TEST(ExprCode, test_mult) {


	int c;
	double res;
	char *argv[] = {"expr.exe", "70", "3", "*"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(210, res);
}

TEST(ExprCode, test_div) {

	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "50", "/"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(10, res);

}

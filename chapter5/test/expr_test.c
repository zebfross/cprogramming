#include "expr.h"
#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_no_args(void) {
	int c;
	double res;
	char *argv[] = {"expr.exe"};
	c = 1;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(0, res);
}

void test_add(void) {

	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "600", "+"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(1100, res);
}

void test_sub(void) {


	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "600", "-"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(-100, res);
}

void test_mult(void) {


	int c;
	double res;
	char *argv[] = {"expr.exe", "70", "3", "*"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(210, res);
}

void test_div(void) {

	int c;
	double res;
	char *argv[] = {"expr.exe", "500", "50", "/"};
	c = 4;
	res = expr(c, argv);
	
	TEST_ASSERT_EQUAL_FLOAT(10, res);

}

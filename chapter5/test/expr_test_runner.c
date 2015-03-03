#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

char MessageBuffer[50];

extern void setUp(void);
extern void tearDown(void);

extern void test_no_args(void);
extern void test_add(void);
extern void test_sub(void);
extern void test_mult(void);
extern void test_div(void);

void resetTest(void);
void resetTest(void) {
	tearDown();
	setUp();
}

int main(void) {
	UnityBegin("test/expr_test.c");

	RUN_TEST(test_no_args);
	RUN_TEST(test_add);
	RUN_TEST(test_sub);
	RUN_TEST(test_mult);
	RUN_TEST(test_div);

	UnityEnd();
	return 0;
}

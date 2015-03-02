#include "strn.h"
#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_strncpy(void) {
	char s[] = "Hello World!", *t = "Goodbye";
	pstrncpy(s, t, 4);
	TEST_ASSERT_EQUAL_STRING("Goodo World!", s);

	pstrncpy(s, t, 400);
	TEST_ASSERT_EQUAL_STRING("Goodbyeorld!", s);
}

void test_strncmp_match(void) {
	int res;
	
	res = pstrncmp("Hello World!", "HelloB", 5);
	TEST_ASSERT_EQUAL(0, res);
}

void test_strncmp_no_match(void) {
	int res;

	res = pstrncmp("Hello World!", "Hollo World!", 5);
	TEST_ASSERT_EQUAL(-1, res);

	res = pstrncmp("Hello World!", "Hallo World!", 5);
	TEST_ASSERT_EQUAL(1, res);
}

void test_strncat(void) {
	char s[20] = "Hello ", *t = "World! and then some";
	pstrncat(s, t, 6);
	TEST_ASSERT_EQUAL_STRING("Hello World!", s);
}

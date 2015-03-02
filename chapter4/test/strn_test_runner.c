#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

char MessageBuffer[50];

extern void setUp(void);
extern void tearDown(void);

extern void test_strncpy(void);
extern void test_strncmp_match(void);
extern void test_strncmp_no_match(void);
extern void test_strncat(void);

void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


int main(void)
{
  UnityBegin("test/strn_test.c");

  RUN_TEST(test_strncpy);
  RUN_TEST(test_strncmp_match);
  RUN_TEST(test_strncmp_no_match);
  RUN_TEST(test_strncat);

  UnityEnd();
  return 0;
}


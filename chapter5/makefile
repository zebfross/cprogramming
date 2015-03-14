SHELL = /bin/sh
UNITY_ROOT = ../unity
CFLAGS = -Wall
INC_DIRS = -Itest -I. -I${UNITY_ROOT} -I${UNITY_ROOT}/fixture
TEST_SRC_FILES = \
	${UNITY_ROOT}/unity.c \
	${UNITY_ROOT}/fixture/unity_fixture.c \
	exercises.c \
	expr.c \
	test/exercises_test.c \
	test/expr_test.c \
	test/exercises_test_runner.c \
	test/expr_test_runner.c \
	test/all_tests.c

getint:
	gcc getint.c ungetch.c -o getint

getfloat:
	gcc getfloat.c ungetch.c -o getfloat

strcat:
	gcc strcat.c -o strcat

strend:
	gcc strend.c -o strend

strn:
	gcc strn.c -o strn

expr:
	gcc ${CFLAGS} expr_main.c expr.c -o expr.exe

tail:
	gcc ${CFLAGS} tail.c utils.c -o tail.exe

tests:
	gcc ${CFLAGS} ${INC_DIRS} ${TEST_SRC_FILES} -o test.exe


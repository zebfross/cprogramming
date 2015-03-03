SHELL = /bin/sh
UNITY_ROOT = ../unity
CFLAGS = -Wall

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

tests1:
	gcc ${CFLAGS} -Itest -I. -I${UNITY_ROOT} ${UNITY_ROOT}/unity.c exercises.c test/exercises_test.c test/exercises_test_runner.c -o test.exe

tests2:
	gcc ${CFLAGS} -Itest -I. -I${UNITY_ROOT} ${UNITY_ROOT}/unity.c expr.c test/expr_test.c test/expr_test_runner.c -o test.exe

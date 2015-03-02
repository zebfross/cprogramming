SHELL = /bin/sh
UNITY_ROOT = ../unity

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

tests:
	gcc -Wall -Itest -I. -I${UNITY_ROOT} ${UNITY_ROOT}/unity.c ${wildcard *.c} ${wildcard test/*.c} -o test.exe


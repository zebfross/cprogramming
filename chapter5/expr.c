#include <stdio.h>
#include "expr.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char *);
void push(double);
double pop(void);
double peek(void);

double expr(int argc, char *argv[]) {
	
	double op2;
	int hasArgs = argc > 1;
	++argv;
	while (--argc > 0) {
		if(isdigit(**argv) || **argv == '_') {
			int sign = (**argv == '_') ? -1 : 1;
			char *num = *argv;
			if(sign < 0)
				num++;
			push(atof(num) * sign);
		} else {
			switch (**argv) {
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					return 0;
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					return 0;
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			default:
				printf("unknown op: %s\n", *argv);
				return 0;
				break;
			}
		}
		++argv;
	}
	if(hasArgs)
		return pop();
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop() {
	if(sp > 0)
		return val[--sp];
	else
		printf("error: stack empty\n");
	return 0.0;
}

double peek() {
	if(sp > 0)
		return val[sp-1];
	else
		printf("error: stack empty\n");
	return 0.0;
}


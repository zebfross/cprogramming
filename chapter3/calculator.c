#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'a'

int getop(char []);
void push(double);
double pop(void);
double peek(void);

/* negative numbers are represented by an underscore '_' instead of a dash */
main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case FUNCTION:
			if(strcmp(s, "sin") == 0)
				push(sin(pop()));
			else if(strcmp(s, "cos") == 0)
				push(cos(pop()));
			else if(strcmp(s, "tan") == 0)
				push(tan(pop()));
			else
				printf("unknown function reference %s\n", s);
			break;
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
				printf("error: zero division\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push((int) pop() % (int) op2);
			else
				printf("error: zero division\n");
			break;
		case '\n':
			printf("\t%.8g\n", peek());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
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

double pop(void) {
	if(sp > 0)
		return val[--sp];
	else
		printf("error: stack empty\n");
	return 0.0;
}

double peek(void) {
	if(sp > 0)
		return val[sp-1];
	else
		printf("error: stack empty\n");
	return 0.0;
}

void swap(void) {
	if(sp > 1) {
		double temp = val[sp-2];
		val[sp-2] = val[sp-1];
		val[sp-1] = temp;
	} else {
		printf("error; stack empty\n");
	}
}

int getch(void);
void ungetch(int);

int getop(char s[]) {
	int i, c, ret;

	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(isalpha(c)) {
		while(isalpha(s[++i] = c = getch()))
			;
		ret = FUNCTION;
	} else {
		if(!isdigit(c) && c != '.' && c != '_')
			return c;
		if(c == '_') {
			s[i] = '-';
		}
		if(c == '_' || isdigit(c))
			while (isdigit(s[++i] = c = getch()))
				;
		if(c == '.')
			while(isdigit(s[++i] = c = getch()))
				;
		ret = NUMBER;
	}
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return ret;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

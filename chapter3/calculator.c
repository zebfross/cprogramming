#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'a'
#define VARIABLE 'v'
#define NUM_VARS 'z' - 'A' + 1

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void dup(void);
void swap(void);
void clear(void);
int isVarDefined(char);
void defineVar(char, double);
double getVar(char);
short varDefs[NUM_VARS];
double vars[NUM_VARS];

/* negative numbers are represented by an underscore '_' instead of a dash */
main() {
	int type;
	double op2;
	char s[MAXOP];

	int i;
	for(i = 0; i < NUM_VARS; ++i)
		varDefs[i] = 0;

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
			else if(strcmp(s, "exp") == 0)
				push(exp(pop()));
			else if(strcmp(s, "swap") == 0)
				swap();
			else if(strcmp(s, "dup") == 0)
				dup();
			else if(strcmp(s, "clear") == 0)
				clear();
			else if(s[0] == '=')
				defineVar(s[1], peek());
			else if(strlen(s) == 1) /* is variable */
				if(isVarDefined(s[0]))
					push(getVar(s[0]));
				else
					printf("error: variable %c is undefined\n", s[0]);
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
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
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

void dup() {
	val[sp] = val[sp - 1];
	++sp;
}

void swap() {
	if(sp > 1) {
		double temp = val[sp-2];
		val[sp-2] = val[sp-1];
		val[sp-1] = temp;
	} else {
		printf("error; less than 2 elements in stack\n");
	}
}

void clear(void) {
	sp = 0;
	printf("stack cleared\n");
}

int getch(void);
void ungetch(int);

int getop(char s[]) {
	int i, c, ret;

	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(isalpha(c) || c == '=') {
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

int isVarDefined(char v) {
	return varDefs['z' - v];
}

void defineVar(char v, double val) {
	varDefs['z' - v] = 1;
	vars['z' - v] = val;
}

double getVar(char v) {
	return vars['z' - v];
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

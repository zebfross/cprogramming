#include <ctype.h>
#include <stdio.h>
#include "ungetch.h"

int getfloat(float *);

int main() {
	int status = 0;
	float num = 0;

	status = getfloat(&num);

	printf("status: %i\n", status);
	printf("result: %f\n", num);

	return 0;
}

int getfloat(float *pn) {
	int c, sign;
	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-') {
		int t = getch();
		if(!isdigit(t) && t != '.') {
			ungetch(t);
			ungetch(c);
			return -1;
		}
	}

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if(c == '.') {
		float dec = 10;
		while(isdigit(c = getch())) {
			*pn = *pn + (c - '0') / dec;
			dec *= 10;
		}
	}
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}


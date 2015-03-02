#include <ctype.h>
#include <stdio.h>
#include "ungetch.h"

int getint(int *);

int main() {
	int num = 0, status = 0;

	status = getint(&num);

	printf("status: %i\n", status);
	printf("result: %i\n", num);

	return 0;
}

int getint(int *pn) {
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
		if(!isdigit(t)) {
			ungetch(t);
			ungetch(c);
			return -1;
		}
	}

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}


#include <stdio.h>

int pstrend(char *, char *);

int main() {
	char s[20] = "hello world", *match = "rld", *no_match = "orl";
	int a = pstrend(s, match);
	int b = pstrend(s, no_match);
	printf("match? %i\nno match? %i\n", a, b);	
}

int pstrend(char *s, char *t) {
	char *ps = s, *pt = t;
	while(*ps)
		ps++;
	while(*pt)
		pt++;
	while(ps - s >= 0 && pt - t >= 0)
		if(*ps-- != *pt--)
			return 0;
	return 1;
}


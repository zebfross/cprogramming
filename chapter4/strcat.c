#include <stdio.h>

void pstrcat(char *, char *);

int main() {
	char s[20] = "hello", *t = " world";
	pstrcat(s, t);
	printf("%s\n", s);	
}

void pstrcat(char *s, char *t) {
	for( ; *s; s++)
		;
	while(*s++ = *t++)
		;
}


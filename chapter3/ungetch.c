#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char[]);

main() {
	int c, i;
	char s[6];
	i = 0;
	while((c = getch()) != EOF) {
		putchar(c);
		if(i < 5)
			s[i++] = c;
		else if(i == 5){
			s[i++] = '\0';
			ungets(s);
		}
			
	}
	ungetch(c);
	c = getch();
	ungetch(c);
	c = getch();
	printf("%i\n", c);
	printf("%i\n", EOF);
	if(c == EOF)
		printf("end of file reached again");
	else
		printf("value of c = %c", c);
	return 0;
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
	printf("%i\n", buf[bufp-1]);
}

void ungets(char s[]) {
	int i = 0;
	while(s[i]) {
		printf("ungetch(%c)\n", s[i]);
		ungetch(s[i++]);
	}
}

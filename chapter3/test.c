#include <stdio.h>

int main() {
	char c;
	while((c = getchar()) != EOF)
		putchar(c);
	c = getchar();
	if(c == EOF)
		printf("end of file reached again");
	return 0;
}

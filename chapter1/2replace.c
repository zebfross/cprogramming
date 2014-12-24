#include <stdio.h>

int main() {
	long c;
	int skip = 0;

	while((c = getchar()) != EOF) {
		if(c == '\t' || c == '\n') {
			putchar('\\');
			if(c == '\t')
				putchar('t');
			else if(c == '\n')
				putchar('n');	
		} else {
			putchar(c);
		}
	}
}

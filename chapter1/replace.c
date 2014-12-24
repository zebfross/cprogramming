#include <stdio.h>

int main() {
	long c;
	int skip = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			skip += 1;		
		} else {
			skip = 0;
		}
		if(skip <= 1)
			putchar(c);
	}
}

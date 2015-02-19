#include <stdio.h>

void printd(int);

int main() {

	printd(123);
	putchar('\n');
	printd(-2005);
	putchar('\n');
}

void printd(int n) {
	if(n < 0) {
		putchar('-');
		n = -n;
	}
	if(n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}


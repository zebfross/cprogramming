#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main() {
	
	unsigned x = 42;
	x = setbits(x, 0, 0, 0);
	printf("%u", x);	
	return 0;
}

/* set n bits of x beginning at position p to the right-most n bits of y,
 * leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, int y) {
	
	return x;
}


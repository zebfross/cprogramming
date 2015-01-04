#include <stdio.h>

void detab(int ntab);

int main() {
	int numSpaces = 4;
	detab(numSpaces);	
}

void detab(int ntab) {
	int c;
	int i;
	int col = 0;
	while((c = getchar()) != EOF) {
		if(c == '\t') {
			int numSpaces = (col % ntab) == 0 ? ntab : (ntab - (col % ntab));
			for (i = 0; i < numSpaces; ++i) {
				putchar(' ');
			}
			col += numSpaces;
		} else {
			putchar(c);
			col++;
		}
		if(c == '\n')
			col = 0;
	}
}


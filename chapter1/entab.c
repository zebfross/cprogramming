#include <stdio.h>

void entab(int tabstop);
int convertSpacesToTabs(int colStart, int tabstop, int nSpaces);

int main() {
	int tabstop = 4;
	entab(tabstop);	
}

void entab(int tabstop) {
	int c, col, nSpaces;
	col = 0;
	nSpaces = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			nSpaces++;
			col++;
		} else {
			if(nSpaces > 0)
				col = convertSpacesToTabs(col, tabstop, nSpaces);
			else
				col++;
			putchar(c);
			nSpaces = 0;
			if(c == '\n')
				col = 0;
		}
	}
	if(nSpaces > 0)
		convertSpacesToTabs(col, tabstop, nSpaces);
}

int convertSpacesToTabs(int colStart, int tabstop, int nSpaces) {
	int offset = tabstop - (colStart % tabstop);
	int nTabs = (nSpaces - offset) / tabstop;
	int remainder = nSpaces - (nTabs * tabstop);
	int colEnd = colStart;
	if(remainder > 0 && remainder >= offset) {
		nTabs++;
		remainder -= offset;
		colEnd += offset;
	}
	for(int i = 0; i < nTabs; i++) {
		putchar('\t');
		colEnd += tabstop;
	}
	for (int i = 0; i < remainder; i++) {
		putchar(' ');
		colEnd += 1;
	}
	return colEnd;
}

#include <stdio.h>

void printLine(char line[], int length);
void copyTailToFront(char line[], int tailStart, int length);

int main() {
	int maxLine = 40;
	int c;
	int tabstop = 4;
	int column = 0;
	int lineLength = 0;
	int lastBlank = 0;
	char line[maxLine];

	while((c = getchar()) != EOF) {
		if(c == '\n') {
			printLine(line, lineLength);
			putchar('\n');
			column = 0;
			lineLength = 0;
			lastBlank = 0;
			continue;
		} else {
			line[lineLength++] = c;
			if(c == '\t')
				column += tabstop - (column % tabstop);
			else
				column++;

			if(c == '\t' || c == ' ')
				lastBlank = lineLength; 
			if(column >= maxLine) {
				column = 0;
				int endOfLine = lineLength;
				if(lastBlank > 0)
					endOfLine = lastBlank;
				printLine(line, endOfLine);
				putchar('\n');
				copyTailToFront(line, endOfLine, lineLength);
				lineLength = lineLength - endOfLine;
				column = lineLength;
			}
		}
	}
	printLine(line, lineLength);
	return 0;
}

void printLine(char line[], int length) {
	int i;
	for (i = 0; i < length; ++i) {
		putchar(line[i]);
	}
}

void copyTailToFront(char line[], int tailStart, int length) {
	int i;
	int j;
	for (i = tailStart, j=0; i < length; ++i, ++j) {
		line[j] = line[i];
	}
}


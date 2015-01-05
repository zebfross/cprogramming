#include <stdio.h>
#define MAX_LINE 500

int main() {
	int i;
	char c;
	char line[MAX_LINE];

	/*for(i = 0; i < MAX_LINE-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
		line[i] = c;
	}*/

	for(i = 0; i < MAX_LINE; ++i) {
		if((c = getchar()) == '\n')
			break;
		if(c == EOF)
			break;
		line[i] = c;
	}

	int j;
	for (j = 0; j < i; ++j)
		putchar(line[j]);

	return 0;
}

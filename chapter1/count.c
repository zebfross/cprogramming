#include <stdio.h>

int main() {
	long c;
	long count = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ')
			++count;
		if(c == '\t')
			++count;
		if(c == '\n')
			++count;
	}
	printf("%d\n", count);
}

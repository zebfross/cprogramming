#include <stdio.h>

int main() {
	int i, j, c, wc, max, state;
	int lengths[40];

	for (i=0; i < 40; i++) {
		lengths[i] = 0;
	}

	wc = 0;
	while((c = getchar()) != EOF) {
		if(c == '\t' || c == '\n' || c == ' ') {
			if(wc > 0)
				lengths[wc-1]++;
			wc = 0;
		} else {
			wc++;
		}
	}
	
	max = 0;
	for(i = 0; i < 40; i++) {
		if(lengths[i] > 0)
			max = i;
	}

	for(i = 0; i <= max; i++) {
		printf("%2d  ", i+1);
		for (j = 1; j <= lengths[i]; j++) {
			printf("|");
		}
		printf("\n");
	}
}

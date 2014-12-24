#include <stdio.h>

int main() {
	int i, j, c, wc, max, maxVal;
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
	
	maxVal = max = 0;
	for(i = 0; i < 40; i++) {
		if(lengths[i] > 0)
			max = i;
		if(lengths[i] > maxVal)
			maxVal = lengths[i];
	}


	for(j = maxVal; j > 0; --j) {
		for(i = 0; i <= max; i++) {
			printf(" ");
			if(lengths[i] >= j) {
				printf("--");
			} else {
				printf("  ");
			}
			if(i < max)
				printf(" ");
		}
		printf("\n");
	}
	for(i = 0; i <= max; i++) {
		printf(" %2d ", i+1);
	}
	printf("\n");
}

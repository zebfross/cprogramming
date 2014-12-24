#include <stdio.h>

int main() {
	float fahr, celc;
	int min, max, step;

	min = 0;
	max = 300;
	step = 20;
	int bogus = 35;

	printf("%lsF\t%lsC\n", L"\176", L"\176");

	fahr = min;
	while(fahr <= max) {
		celc = 5 * (fahr - 32) / 9;
		printf("%3.0f\t%6.1f\n", fahr, celc);
		fahr += step;
	}


}

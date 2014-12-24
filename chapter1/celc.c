#include <stdio.h>

int main() {
	float celc, fahr;

	int min, max, step;

	min = -100;
	max = 125;
	step = 10;

	celc = min;

	while(celc <= max) {
		fahr = celc * (9.0/5.0) + 32.0;
		printf("%3.0f\t%6.1f\n", celc, fahr);
		celc = celc + step;
	}
}

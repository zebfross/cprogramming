#include "expr.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	float res;
	res = expr(argc, argv);

	printf("%f\n", res);

	return 0;
}

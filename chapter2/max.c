#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {
	printf("Min schar: %i\n", SCHAR_MIN);
	printf("Max schar: %i\n", SCHAR_MAX);

	printf("Min uchar: %i\n", 0);
	printf("Max uchar: %i\n", UCHAR_MAX);

	printf("Min char: %i\n", CHAR_MIN);
	printf("Max char: %i\n", CHAR_MAX);

	printf("Min short: %i\n", SHRT_MIN);
	printf("Max short: %i\n", SHRT_MAX);

	printf("Min ushort: %i\n", 0);
	printf("Max ushort: %i\n", USHRT_MAX);

	printf("Min int: %i\n", INT_MIN);
	printf("Max int: %i\n", INT_MAX);

	printf("Min uint: %i\n", 0);
	printf("Max uint: %u\n", UINT_MAX);

	printf("Min long: %li\n", LONG_MIN);
	printf("Max long: %li\n", LONG_MAX);

	printf("Min ulong: %i\n", 0);
	printf("Max ulong: %lu\n", ULONG_MAX);

	printf("Min llong: %lli\n", LLONG_MIN);
	printf("Max llong: %lli\n", LLONG_MAX);

	printf("Min ullong: %i\n", 0);
	printf("Max ullong: %llu\n", ULLONG_MAX);

	printf("Min float: %f\n", FLT_MIN);
	printf("Max float: %f\n", FLT_MAX);

	printf("Min double: %f\n", DBL_MIN);
	printf("Max double: %f\n", DBL_MAX);

	return 0;

}

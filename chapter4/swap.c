#include <stdio.h>
#define swap(t, x, y) {\
	t _zzz = x;\
	x = y;\
	y = _zzz;\
}

int main() {
	int a = 2, b = 3;
	printf("a %i b %i\n", a, b);

	swap(int, a, b);

	printf("a %i b %i\n", a, b);

	char * str1 = "Hello", * str2 = "Cool";
	printf("1 %s 2 %s\n", str1, str2);

	swap(char *, str1, str2);

	printf("1 %s 2 %s\n", str1, str2);
}

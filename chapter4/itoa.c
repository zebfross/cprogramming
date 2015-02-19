#include <stdio.h>
#include <stdlib.h>

void itoa(int, char[]);

int main() {
	char buffer[33];
	
	itoa(1005, buffer);
	printf("1005 -> %s\n", buffer);
	itoa(-2123532, buffer);
	printf("-2123532 -> %s\n", buffer);
}

int _itoa(int, char[], int);

void itoa(int value, char str[]) {
	int pos;
	pos = _itoa(value, str, 0);
	str[pos] = '\0';
}

int _itoa(int value, char str[], int pos) {
	if(value < 0) {
		str[pos++] = '-';
		value = -value;
	}
	if(value / 10) {
		pos = _itoa(value / 10, str, pos);
	}
	str[pos++] = (value % 10) + '0';
	return pos;
}


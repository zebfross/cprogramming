#include <stdio.h>

int strindex(char s[], char t);

int main() {
	char s[] = "What is the index of the right-most x in this string?";

	printf("index of x: %i\n", strindex(s, 'x'));

	printf("index of z: %i\n", strindex(s, 'z'));

	return 0;
}

int strindex(char s[], char t) {
	int pos = -1;
	int i;
	
	for(i = 0; s[i] != '\0'; ++i) {
		pos = (s[i] == t) ? i : pos;
	}
	return pos;
}


#include <stdio.h>

void lower(char s[]);

int main() {
	
	char s[] = "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.";

	lower(s);
	
	printf("%s", s);
	return 0;
}

void lower(char s[]) {
	int i;
	for(i = 0; s[i] != '\0'; ++i) {
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - ('A' - 'a') : s[i];
	}	
}

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
	
	char s1[] = "abc123def34htn";
	char s2[] = "1234";
	squeeze(s1, s2);
	
	return 0;
}

void squeeze(char s1[], char s2[]) {
	printf("squeezing s1: %s\t and s2: %s\n", s1, s2);

	int i, j, k = 0;
	for(i = 0; s1[i] != '\0'; ++i) {
		int contained = 0;
		for(j = 0; s2[j] != '\0'; ++j) {
			if(s1[i] == s2[j]) {
				contained = 1;
			}
		}
		if(!contained) {
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';

	printf("result: %s\n", s1);
}


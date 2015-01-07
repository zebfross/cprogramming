#include <stdio.h>

void expand(char s[], char t[]);

int main() {
	int max_string = 200;
	char s[] = "A-Zand0-9c-p-w- -3-7-2a-z";
	char t[max_string];

	expand(s, t);

	printf("expanded: %s\n", t);

	return 0;
}

void expand(char s[], char t[]) {
	int i, j;
	
	for(i = 0, j=0; s[i] != '\0'; ++i) {
		char c = s[i];
		if(i > 0 && s[i] == '-') {
			char p = s[i-1];
			char n = s[i+1];
			if(p >= 'a' && p <= 'z' && n >= 'a' && n <= 'z') {
			} else if (p >= 'A' && p <= 'Z' && n >= 'A' && n <= 'Z') {
			} else if (p >= '0' && p <= '9' && n >= '0' && n <= '9') {
			} else {
				t[j++] = c;
				continue;
			}
			int diff = n - p;
			signed int inc = (0 < diff) - (diff < 0);
			diff *= inc;
			printf("%i\n", inc);
			char next;
			for(next = p + inc; diff > 0; diff--) {
				t[j++] = next;
				next += inc;
			}
			i++;
		} else {
			t[j++] = c;
		}
	}	
	t[j] = '\0';
}


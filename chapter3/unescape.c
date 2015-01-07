#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
	int max_string = 100;
	char s1[] = "Some \t\t Tabs \nAnd don't forget some new lines\n";
	char result[max_string];

	printf("escaping: %s\n", s1);

	escape(s1, result);

	printf("escaped: %s\n", result);

	unescape(result, s1);

	printf("unescaped: %s\n", s1);

	return 0;
}

void escape(char s[], char t[]) {
	int i, j;

	for(i = 0, j = 0; s[i] != '\0'; ++i) {
		switch (s[i]) {
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = s[i];
				break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;

	for(i = 0, j = 0; s[i] != '\0'; ++i) {
		if(s[i] == '\\' && s[i+1] == 'n') {
			t[j++] = '\n';
			i++;
		} else if (s[i] == '\\' && s[i+1] == 't') {
			t[j++] = '\t';
			i++;
		} else {
			t[j++] = s[i];
		}
	}

	t[j] = '\0';
}


#include <stdio.h>
#include <stdlib.h>

void reverse(char *);

int main() {
	char buffer[] = "Helloo";
	reverse(buffer);
	printf("%s\n", buffer);
}

void reverse(char *str) {
	
	void _reverse(char *, char *);

	char *ps = str;
	while(*ps)
		ps++;
	_reverse(str, ps - 1);
}

void _reverse(char *str, char *ps) {
	if(ps > str) {
		char temp = *ps;
		*ps = *str;
		*str = temp;
		_reverse(++str, --ps);
	}		
}

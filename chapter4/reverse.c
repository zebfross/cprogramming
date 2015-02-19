#include <stdio.h>
#include <stdlib.h>

void reverse(char[]);

int main() {
	char buffer[] = "Helloo";
	reverse(buffer);
	printf("%s\n", buffer);
}

void reverse(char str[]) {
	
	void _reverse(char[], int, int);

	int end;
	end = 0;
	while(str[end] != '\0')
		end++;
	_reverse(str, 0, end - 1);
}

void _reverse(char str[], int start, int end) {
	if(end > start) {
		char temp = str[end];
		str[end] = str[start];
		str[start] = temp;
		_reverse(str, ++start, --end);
	}		
}

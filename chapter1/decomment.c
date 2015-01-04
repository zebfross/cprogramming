#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	int c;
	int inString = OUT;
	int inComment = OUT;
	int inCharacter = OUT;
	int escapeChars = 0;
	int skipChars = 0;
	char buffer[2];

	c = getchar();
	if(c == EOF)
		return 0;
	buffer[1] = c;
	while((c = getchar()) != EOF) {
		buffer[0] = buffer[1];
		buffer[1] = c;

		/* test if in string "" */
		if(buffer[0] == '"')
			if(!inComment && !inCharacter && !escapeChars)
				inString = !inString;
	
		/* test if in character constant '"' */
		if(buffer[0] == '\'')
			if(!inComment && !inString && !escapeChars)
				inCharacter = !inCharacter;

		/* test if escape character */
		if(buffer[0] == '\\')
			if(!inComment && (inString || inCharacter))
				escapeChars = 2;

		/* test if in comment */
		if(buffer[0] == '/' && buffer[1] == '*') {
			if(!inString) {
				inComment = IN;
			}
		}

		/* test if out of comment */
		if(inComment && buffer[0] == '*' && buffer[1] == '/') {
			skipChars = 2;
			inComment = OUT;
		}

		/* print characters if not in comment */
		if(!inComment) {
			if(skipChars)
				skipChars--;
			else
				putchar(buffer[0]);
		}
		if(escapeChars)
			escapeChars--;
	}
	/* print last character, if not in comment of course */
	if(!inComment && !skipChars)
		putchar(buffer[1]);
	
	return 0;
}

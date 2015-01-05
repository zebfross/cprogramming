#include <stdio.h>
#define MAX_DEPTH 1000
#define TRUE 1
#define FALSE 0

int push(char c);
char pop(void);
void printInvalid();
void printValid();
int lineNum = 0;
int column = 0;

int main() {
	char c;
	int inString = 0;
	int inComment = 0; 
	int inCharacter = 0;
	int escapeChars = 0;
	char buffer[2];

	c = getchar();
	buffer[1] = c;
	while(buffer[1] != EOF) {
		buffer[0] = buffer[1];
		buffer[1] = c = getchar();
		column++;
		if(buffer[0] == '\n') {
			lineNum++;
			column = 0;
		}

		if(buffer[0] == '\\' && !escapeChars && (inString || inCharacter))
			escapeChars = 2;

		if(buffer[0] == '"' && !inCharacter && !escapeChars && !inComment)
			inString = !inString;

		if(buffer[0] == '\'' && !inString && !escapeChars)
			inCharacter = !inCharacter;

		if(buffer[1] != EOF && !inString) {
			if(buffer[0] == '/' && buffer[1] == '*') {
				if(inComment) {
					printInvalid("Nested comments are not allowed");
					return 1;
				}
				inComment = TRUE;
			}
			if(buffer[0] == '*' && buffer[1] == '/') {
				if(!inComment) {
					printInvalid("Trailing comment without matching /*");
					return 1;
				}
				inComment = FALSE;
			}
		}

		if(!inString && !inCharacter && !escapeChars && !inComment) {
			int isValid = TRUE;
			if(buffer[0] == '[' || buffer[0] == '{' || buffer[0] == '(') {
				isValid = push(buffer[0]);
				if(!isValid) {
					printInvalid("Maximum stack size reached");
					return 1;
				} else {
				}
			} else if(buffer[0] == ']' || buffer[0] == '}' || buffer[0] == ')') {
				char stackTop = pop();
				if(buffer[0] == ']' && stackTop != '[') {
					printf("stack top: %c", stackTop);
					isValid = FALSE;
				} else if(buffer[0] == '}' && stackTop != '{') {
					printf("stack top: %c", stackTop);
					isValid = FALSE;
				} else if(buffer[0] == ')' && stackTop != '(') {
					printf("stack top: %c", stackTop);
					isValid = FALSE;
				}
				if(!isValid) {
					char message[15] = "Unexpected '%'";
					message[12] = buffer[0];
					printInvalid(message);
					return 1;
				}
			}
		}

		if(escapeChars)
			escapeChars--;
	}

	char remainder = pop();
	if(inString) {
		printInvalid("Missing ending double quote");
		return 1;
	} else if(inCharacter) {
		printInvalid("Missing ending single quote");
		return 1;
	} else if(remainder != 0) {
		char message[20] = "Missing closing '%'";
		message[17] = remainder;
		printInvalid(message);
		return 1;
	}

	printValid();
	return 0;
}

char stack[MAX_DEPTH];
int position = -1;

int push(char c) {
	if(position >= MAX_DEPTH)
		return FALSE;
	stack[++position] = c;
	return TRUE;
}

char pop() {
	if(position < 0)
		return FALSE;
	return stack[position--];
}

void printInvalid(char message[]) {
	printf("Error on line %i column %i\n", lineNum, column);
	printf("Message: %s", message);
}

void printValid() {
	printf("Valid");
}



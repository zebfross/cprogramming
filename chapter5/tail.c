#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX_LINES 5000
#define DEFAULT_LINES 10

char *lines[MAX_LINES];
int num_lines = DEFAULT_LINES;

void parse_command_line(int, char *[]);
char *read_line(int *);

int main(int argc, char *argv[]) {

	parse_command_line(argc, argv);

	int i, len, line_len;
	
	if(num_lines <= 0)
		return 0;

	i = 0, len = 0, line_len = 0;
	char *p;
	while(1) {
		p = read_line(&line_len);
		if(line_len == 0)
			break;
		if(len > num_lines)
			free(lines[i]);
		lines[i] = p;
		i += 1;
		if(i >= num_lines)
			i = 0;
		len += 1;
	}

	int ref = i;
	for(i; i < num_lines && i < len; ++i) {
		printf("%s\n", lines[i]);
		free(lines[i]);
	}
	i = 0;
	for(i; i < ref; ++i) {
		printf("%s\n", lines[i]);
		free(lines[i]);
	}

	return 0;
}

void parse_command_line(int argc, char *argv[]) {
	if(argc < 2)
		return;
	if(*argv[1] == '-') {
		num_lines = atoi(++argv[1]);
	}
}

#define MAX_LINE 1000

char * read_line(int *line_len) {
	int len;
	char *p, line[MAX_LINE];

	len = get_line(line, MAX_LINE);

	if(len > 0) {
		p = malloc(len);
		line[len-1] = '\0';
		strcpy(p, line);
	}
	(*line_len) = len;
	return p;
}


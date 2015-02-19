#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 20

struct Node {
	int id;
	int *edges;
};

struct Table {
	double **weights;
};

int V, E, u, v;
double w;
struct Table table;

int nextInt();
double nextDouble();
void initialize();
void deconstruct();

int main() {
	
	initialize();
	
	deconstruct();
}

void initialize() {
	
	char line[MAX_LINE];

	fgets(line, MAX_LINE, stdin);

	sscanf(line, "%i %i", &V, &E);
	
	int i, j;
	table.weights = (double **)malloc(sizeof(double *) * V);
	for(i = 0; i < V; ++i) {
		table.weights[i] = (double *)malloc(sizeof(double) * V);
	}

	for(i = 0; i < E; ++i) {
		
	}

	for(i = 0; i < V; ++i) {
		for(j = 0; j < V; ++j) {
			table.weights[i][j] = -1;
		}
	}

}

void deconstruct() {
	
	int i;
	for(i = 0; i < V; ++i) {
		free(table.weights[i]);
	}
	free(table.weights);
}


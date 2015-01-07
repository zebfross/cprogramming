#include <stdio.h>

int binsearch(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && v[mid] != x) {
		mid = (low + high) / 2;
		if(x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if(low <= high)
		return mid;
	return -1;
}

int main() {
	int n = 15;
	int v[n];
	int i, res;

	for (i = 0; i < n; ++i)
		v[i] = i+1;

	res = binsearch(12, v, n);

	printf("result: %i", res);

	return 0;
}

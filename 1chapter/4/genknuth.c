#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 10000000
#define COUNT 1000000

/**
Select n from m
*/
void genknuth(int m, int n, int *arr);

int main() {
	int arr[COUNT];
	genknuth(MAX, COUNT, arr);
	FILE* f = fopen("data.txt", "wb");
	for (int i = 0; i < COUNT; i++) {
		fprintf(f, "%d\n", arr[i]);
	}
	fclose(f);
	return 0;
}

void genknuth(int m, int n, int *arr) {
	int *data = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; ++i) {
		data[i] = i;
	}

	srand(time(NULL));
	int top = 0;
	for (int i = 0; i < n; ++i) {
		int index = rand() % m;
		arr[top++] = data[index];
		data[index] = data[m - 1];
		m--;
	}
	free(data);
}

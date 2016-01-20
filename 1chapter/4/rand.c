#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 	10000000
#define COUNT 	1000000

int a[MAX];
void swap(int *i, int *j);
void generate(int max, int count,  int *arr);

int main() {
	generate(MAX, COUNT, a);	
}

void generate(int max, int count, int *arr) {
	FILE* file = fopen("data.txt", "wb");
	for (int i = 0; i < max; i++)
		a[i] = i;
	
	srand(time(NULL));
	for (int i = 0; i < max; i++) {
		int index = rand() % max;
		if (index&2) {
			swap(arr + i, arr + index);
		} else {
			swap(arr + i, arr + max - 1 - index);
		}
	}
	
	for (int i = 0; i < count; i++) {
		fprintf(file, "%d\n", arr[i]);
	}
	fclose(file);
}

void swap(int *i, int *j) {
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

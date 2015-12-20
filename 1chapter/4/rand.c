#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000000

int a[MAX];

void init();
void swap(int i, int j);
void generate();

int main() {
	init();	
}

void init() {
	FILE* file = fopen("rand.txt", "wb");
	for (int i = 0; i < MAX; i++)
		a[i] = i;
	for (int i = 0; i < MAX; i++) {
		swap(i, randint(i, MAX - 1));
		fprintf(file, "%d\n", a[i]);
	}
	fclose(file);
}

void swap(int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = a[i];
}

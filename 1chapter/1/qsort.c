#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

/* Select n from m and store into arr */
void genunsort(int m, int n, int *arr);

int intcmp(const int *x, const int *y) {
	return *x - *y;
}

int a[MAX];

int main(void) {
	genunsort(MAX, MAX, a);
	FILE* data = fopen("data.txt", "wb");
	for (int i = 0;  i < MAX; i++) {
		fprintf(data, "%d\n", a[i]);
	}
	fclose(data);

	qsort(a, MAX, sizeof(int), intcmp);
	FILE* f = fopen("res.txt", "wb");
	for (int i = 0; i < MAX; i++) {
		fprintf(f, "%d\n", a[i]);
	}
	fclose(f);
}

void genunsort(int m, int n, int *arr) {
	int *data = (int *)malloc(sizeof (int) * m);
	for (int i = 0; i < m; i++) {
		data[i] = i;
	}
	srand(time(NULL));
	int top = 0;
	for (int i = 0; i < n; i++) {
		int index = rand() % m;
		arr[top] = data[index];
		data[index] = data[m - 1];
		m--;	
		top++;
	}
	free(data);
}

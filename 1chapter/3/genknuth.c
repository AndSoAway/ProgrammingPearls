#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 	10000000
#define COUNT 	1000000

/**
Select n from m
*/
void genknuth(int m, int n, int *arr);

#define INTSIZE 4
#define BITPERTYPE INTSIZE * 8
#define SHIFT 5
#define MASK 0x1F

int a[1 + MAX / BITPERTYPE];

void set(int i) { a[i >> SHIFT] |= (1 << (i & MASK)); }
void clr(int i) { a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) { return a[i >> SHIFT] & (1 << (i & MASK)); }

int main() {
	int data[COUNT] ;
	
	for (int i = 0;  i < MAX; i++) {
		clr(i);
	}
	genknuth(MAX, COUNT, data);
	
	clock_t begin, end;
	begin = clock();
	for (int i = 0; i < COUNT; i++) {
		set(data[i]);
	}
	end = clock();
	printf("cost time %lfms\n", (double)(end - begin) / CLOCKS_PER_SEC * 1000);
	FILE* res = fopen("res.txt", "wb");
	for (int i = 0; i < MAX; i++) {
		if (test(i)) {
			fprintf(res, "%d\n", i);
		}
	}
	fclose(res);
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

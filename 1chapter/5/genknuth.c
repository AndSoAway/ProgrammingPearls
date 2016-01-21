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

#define K 2
#define MEM MAX / K
#define BITSIZE 1 + MEM / BITPERTYPE
int a[BITSIZE];

void set(int i) { a[i >> SHIFT] |= (1 << (i & MASK)); }
void clr(int i) { a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) { return a[i >> SHIFT] & (1 << (i & MASK)); }

int main() {
	int data[COUNT] ;
	
	for (int i = 0;  i < MAX; i++) {
		clr(i);
	}
	genknuth(MAX, COUNT, data);
	
	FILE* res = fopen("res.txt", "wb");
	clock_t begin, end;
	begin = clock();
	clock_t cal_cost;
	for (int k = 0; k < K; k++) {
		clock_t begin_cal = clock();
		int lower = k * MAX / K;
		int upper = (k + 1) * MAX / K;
		for (int i = 0; i < COUNT; i++) {
			if (data[i] >= lower && data[i] < upper) {
				set(data[i] - lower);
			}
		}
		cal_cost += clock() - begin_cal;
		for (int i = 0; i < BITSIZE; i++) {
			if (test(i)) {
				fprintf(res, "%d\n", i + lower);
			}
		}
	}
	fclose(res);
	end = clock();
	printf("cost time %lfms\n", (double)(end - begin) / CLOCKS_PER_SEC * 1000);
	printf("cal cost time %lfms\n", (double)(cal_cost) / CLOCKS_PER_SEC * 1000);
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

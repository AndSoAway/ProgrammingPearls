#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

long long bigrand();

int randint(int l, int u);

void genknuth(int n, int m, int *num);

int main() {
	int n = INT_MAX, m = 10;
	int *num = (int*)malloc(sizeof(int) * m);
	genknuth(n, m, num);
	for (int i = 0; i < m; i++) {
		printf("%d\n", num[i]);
	}
}

long long bigrand() {
	long long res = rand(); 
	res = res * RAND_MAX + res + rand();
	return res;
}

int randint(int l, int u) {
	return l + bigrand() % (u - l + 1);
}

void genknuth(int n, int m, int *num) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (bigrand() % (n - i) < m) {
			num[count++] = i;
		}
	}
}

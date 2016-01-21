#include<cstdio>

using namespace std

int gcd(int n, int m);

void acro_rotate(int *begin, int *end, int n);

void rangeswap(int *begin1, int *begin2, int n);

void recur_rotate(int *begin, int *end, int n);

void three_rotate(int *begin, int *end, int n);

int main() {
	int *str = {0,1,2,3,4,5,6,7,8,9};
		
}

int gcd(int n, int m) {
	if (n == 0)
		return 0;
	if (m == 0) {
		return n;
	}
	if (n < m) {
		swap(n, m);
	}
	if(n % m == 0) {
		return m;
	}

	return gcd(m, n % m);
}

void acro_rotate(int *begin, int *end, int n) {
	int len = end - begin;
	int n = n % len;
	int rounds = gcd(len, n);
	int count_per = len / rounds;
	for (int i = 0; i < rounds; i++) {
		int tmp = *(begin + i);
		int pre = i;
		int cur = (pre + n) % len;
		while (cur != i) {
			*(begin + pre) = *(begin + cur);
			pre = cur;
			cur = (pre + n) % len;
		}
		*(begin + pre) = tmp;		
	}
}

void rangeswap(int *begin1, int *begin2, int n) {
	for (int i = 0; i < n; i++) {
		int tmp = *(begin1 + i);
		*(begin1 + i) = *(begin2 + i);
		*(begin2 + i) = tmp;
	}
}

void recur_rotate(int *begin, int *end, int n) {
	int len = end - begin;
	n = n % len;
	int *l1, *l2, *r1, *r2;
	l1 = l2 = r1 = r2 = NULL;
	if (n < len - n) {
		rangeswap(begin, end - n, n);
		recur_rotate(begin, begin + len - n, n);
	} else {
		rangeswap(begin, begin + n, len - n);
		recur_rotate(begin + len - n, end, 2 * n - len);
	}
}

void flip_rotate(int *begin, int *end, int n) {
	int len = end - begin;
	n = n % len;
	for (int lower = 0, high = n - 1; lower < high; lower++, high--) {
		int tmp = *(begin + lower);
		*(begin + lower) = *(begin + high);
		*(begin + high) = tmp;
	}
	for (int lower = n, high = len - 1; lower < high; lower++, high--) {
		int tmp = *(begin + lower;
		*(begin + lower) = *(begin + high);
		*(begin + high) = tmp;
	}
	for (int lower = 0, high = len - 1; lower < high; lower++, high--) {
		int tmp = *(begin + lower);
		*(begin + lower) = *(begin + high);
		*(begin + high) = tmp;
	}
}

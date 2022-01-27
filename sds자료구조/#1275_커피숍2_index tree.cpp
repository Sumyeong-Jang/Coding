#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXQ 18

int N, Q, B;
long long IDT[1 << MAXQ];

void initIDT() {
	for (int i = B - 1; i > 0; i--) {
		IDT[i] = IDT[i << 1] + IDT[(i << 1) | 1];
	}
}

long long lgSum(int l, int r) {
	if (l > r) swap(l, r);
	l = B + l - 1; r = B + r - 1;
	long long sum = 0;
	while (l <= r) {
		if (l % 2 == 1) sum += IDT[l];
		if (r % 2 == 0) sum += IDT[r];

		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return sum;
}

void update(int a, long long b) {
	a = B + a - 1;
	IDT[a] = b;

	while (a >>= 1) {
		IDT[a] = IDT[a << 1] + IDT[(a << 1) | 1];
	}
}

int main() {
	scanf("%d %d", &N, &Q);
	for (B = 1; B < N; B <<= 1);
	for (int i = 0; i < N; i++) {
		scanf("%lld ", &IDT[B + i]);
	}
	initIDT();

	int x, y, a;
	long long b;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %lld", &x, &y, &a, &b);
		printf("%lld\n", lgSum(x, y));
		update(a, b);
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXK 21

int N, M, K;
int B, T;
long long IDT[1 << MAXK] = { 0 };

void initIDT() {
	for (int i = B - 1; i > 0; i--)
		IDT[i] = (IDT[i << 1] + IDT[(i << 1) | 1]);
}

void update(int p, long long v) {
	p = B + p - 1;
	IDT[p] = v;
	
	// 숫자 바꾼 후 부모 합 업데이트
	while (p >>= 1)
		IDT[p] = IDT[p << 1] + IDT[(p << 1) | 1];
}

long long lgSum(int l, int r)
{
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

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	// B: 깊이별 시작 인덱스 && 최하위 노드 갯수
	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++)
		scanf("%lld", &IDT[i]);	//왜 long long으로 입력받지?
	initIDT();

	T = M + K; // T는 수 변경 + 구간 합 구하는 횟수

	int a, b;
	long long c;
	while (T--)
	{
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) update(b, c);
		else printf("%lld\n", lgSum(b, (int)c));
	}
	return 0;
}

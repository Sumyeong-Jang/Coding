#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int find_maxIndex(char N[], int M, int K, int start);
void change(char N[], int idx, int maxIdx);

int main()
{
	char N[10]; int K, M, idx, maxIdx; scanf("%s %d", &N, &K);
	idx = 0; maxIdx = 0; M = strlen(N);
	if (M <= 1) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < K; i++) {
		while (idx != M - 2) {
			if (find_maxIndex(N, M, K, idx) == idx)
				idx++;
			else break;
		}

		if (M - 1 - idx == 1) maxIdx = idx + 1;
		else maxIdx = find_maxIndex(N, M, K, 1);

		if (idx == 0 && N[maxIdx] == '0') {
			printf("-1");
			return 0;
		}
		else change(N, idx, maxIdx);
	}
	printf("%s", N);
	return 0;
}

void change(char N[], int idx, int maxIdx)
{
	int tmp; tmp = N[idx];
	N[idx] = N[maxIdx];
	N[maxIdx] = tmp;
}

int find_maxIndex(char N[], int M, int K, int start)
{
	int max, maxIdx; max = 0; maxIdx = 1;
	for (int i = start; i < M; i++) {
		if (max <= N[i] - '0') {
			max = N[i] - '0';
			maxIdx = i;
		}
	}
	return maxIdx;
}

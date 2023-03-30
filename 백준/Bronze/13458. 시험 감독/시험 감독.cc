#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int solution(int A, int B, int C);
int A[1000001] = { 0 };

int main()
{
	// N(시험장), A(i)(응시자수), B(총감), C(부감)
	int N, B, C;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf(" %d", &A[i]);
	scanf("%d %d", &B, &C);

	long long result = 0;
	for (int i = 0; i < N; i++)
		result += (long long)solution(A[i], B, C);
	printf("%lld", result);
	return 0;
}

int solution(int A, int B, int C)
{
	int n = 1, tmp = 0;
	if (A - B > 0) {
		A = A - B;
		tmp = A / C;
		if (A % C == 0)
			n = n + tmp;
		else
			n = n + tmp + 1;
	}
	return n;
}
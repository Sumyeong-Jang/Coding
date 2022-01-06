#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main()
{
	char N[10]; int K; scanf("%s %d", N, &K);
	int M = strlen(N);
	int tmp = 0;

	string str = N;
	queue<string> q;

	q.push(str);

	for (int k = 0; k < K; k++) {
		// k번 연산한 결과값들 queue에 저장
		// 저장된 숫자 선입선출로 연산 (queue에 있는 만큼)
		// 꼭 queue여야해? 그냥 배열에 저장! but string.
		set<string> s;
		int size = q.size();

		for (int x = 0; x < size; x++) {
			str = q.front();
			q.pop();

			if (s.count(str) == 1) continue;
			s.insert(str);

			for (int i = 0; i < M - 1; i++) {
				for (int j = i + 1; j < M; j++) {
					if (i == 0 && str[j] == '0') continue;
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;

					q.push(str);
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
				}
			}
		}
	}
	// 마지막 queue에 있는 값 중 max 추출 & 출력
	string ans = "0";
	while (!q.empty()) {
		ans = max(ans, q.front());
		q.pop();
	}
	if (ans[0] == '0') printf("-1");
	else printf("%s", ans.c_str());

	return 0;
}

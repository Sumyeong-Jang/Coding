#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s1, s2;
int l;
int dp[1001][1001];
vector<char> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s1);
	getline(cin, s2);

	memset(dp, 0, sizeof(dp));
	l = 0;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1.at(i - 1) == s2.at(j - 1)) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				//이전 상황으로 되돌리기
				//(i증가였는지 j증가였는지 모르니까)

				//또는 현재까지의 길이 저장 & update
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	l = dp[s1.length()][s2.length()];
	printf("%d\n", l);

	if (l > 0) {
		int x = s1.length();
		int y = s2.length();
		v.clear();

		while (true) {
			if (x == 0 || y == 0) break;
			if (s1[x - 1] == s2[y - 1]) {
				v.push_back(s1[x - 1]);
				x--;
				y--;
			}
			else {
				if (dp[x][y] == dp[x - 1][y]) {
					x--;
				}
				else if (dp[x][y] == dp[x][y - 1]) {
					y--;
				}
			}
		}
		while (true) {
			if (v.empty()) break;
			printf("%c", v.at(v.size() - 1));
			v.pop_back();
		}
	}
	return 0;
}

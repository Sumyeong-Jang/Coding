#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans;
char board[51][51];
bool isVisited[51][51];
int DP[51][51]; //계산결과 저장해둠 (중복계산을 막기 위해)

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool dfs(int x, int y, int cnt);

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);
	dfs(0, 0, 1);
	printf("%d", ans);
}

bool dfs(int x, int y, int cnt) {
	// 무한번 움직일 수 있는 경우
	if (ans == -1) return true;
	ans = max(ans, cnt);

	isVisited[x][y] = true;
	DP[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (board[x][y] - '0');
		int ny = y + dy[i] * (board[x][y] - '0');

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 'H') continue;

		if (isVisited[nx][ny]) {
			ans = -1;
			return true;
		}
		if (DP[nx][ny] > 0 && cnt < DP[nx][ny]) continue;

		if (dfs(nx, ny, cnt + 1))
			return true;
	}
	isVisited[x][y] = false;
	return false;
}

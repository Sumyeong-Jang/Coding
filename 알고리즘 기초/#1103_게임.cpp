#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M, Ans;
char board[51][51];
bool visit[51][51];
int dp[51][51]; // 중복계산을 막기 위해 계산 결과 저장

//방향 (왼쪽, 아래, 위, 오른쪽)
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

bool dfs(int x, int y, int cnt);

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);

	dfs(0, 0, 1);
	printf("%d", Ans);
}

bool dfs(int x, int y, int cnt)
{
	// 무한번 움직일 수 있는 경우
	if (Ans == -1)
		return true;

	Ans = max(Ans, cnt);

	visit[x][y] = true;
	dp[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (board[x][y] - '0');
		int ny = y + dy[i] * (board[x][y] - '0');

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 'H')
			continue;

		if (visit[nx][ny]) {
			Ans = -1;
			return true;
		}

		if (dp[nx][ny] > 0 && cnt < dp[nx][ny])
			continue;

		if (dfs(nx, ny, cnt + 1))
			return true;
	}
	visit[x][y] = false;
	return false;
}

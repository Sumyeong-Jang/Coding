#include <iostream>

using namespace std;

int N, M;
int input;
int from, to;
int dp[100001];
int answer;

int main(int argc, char** argv) {

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &input);
        dp[i] += dp[i - 1] + input;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &from);
        scanf("%d", &to);
        answer = dp[to] - dp[from - 1];
        printf("%d\n", answer);
    }

    return 0;
}

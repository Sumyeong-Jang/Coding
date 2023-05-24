import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

dp = [1] * n

for i in range(1, n):
    m = 0
    for j in range(i):
        if A[j] < A[i]:
            m = max(m, dp[j])
    dp[i] = m + 1

print(max(dp))

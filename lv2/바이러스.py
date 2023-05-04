K, P, N = map(int, input().split())

for _ in range(N):
    K = K * P
    K = K % 1000000007

print(K)

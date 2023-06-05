N = int(input())
T, P = [], []
for i in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

result = [0 for _ in range(N + 1)]
max_result = 0

for i in range(N - 1, -1, -1):
    time = T[i] + i
    if time <= N:
        result[i] = max(P[i] + result[time], max_result)
        max_result = result[i]
    else:
        result[i] = max_result
print(max_result)
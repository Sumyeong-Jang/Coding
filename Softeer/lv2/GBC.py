N, M = map(int, input().split())
elev_limit = [0 for _ in range(100)]

idx = 0
for i in range(N):
    limit_m, limit_s = map(int, input().split())
    for i in range(idx, idx + limit_m):
        elev_limit[i] = limit_s
    idx += limit_m
    
over = [0]
idx = 0
for i in range(M):
    oper_m, oper_s = map(int, input().split())
    for i in range(idx, idx + oper_m):
        if (elev_limit[i] < oper_s):
            over.append(oper_s - elev_limit[i])
    idx += oper_m

print(max(over))

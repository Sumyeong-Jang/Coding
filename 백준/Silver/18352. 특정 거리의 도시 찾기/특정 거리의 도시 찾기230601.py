from collections import deque

n, m, k, x = map(int, input().split())

mmap = [[] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    A, B = map(int, input().split())
    mmap[A].append(B)

dist = [0] * (n + 1)
visited = [False] * (n + 1)
q = deque()
q.append(x)
while q:
    v = q.popleft()
    visited[v] = True
    for i in range(len(mmap[v])):
        if not visited[mmap[v][i]]:
            q.append(mmap[v][i])
            if dist[mmap[v][i]] != 0:
                dist[mmap[v][i]] = min(dist[v] + 1, dist[mmap[v][i]])
            else:
                dist[mmap[v][i]] = dist[v] + 1
check = False
for i in range(1, n + 1):
    if dist[i] == k:
        check = True
        print(i)
if not check:
    print(-1)

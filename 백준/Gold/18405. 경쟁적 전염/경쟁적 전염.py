N, K = map(int, input().split())

data = []
start = []
for i in range(N):
    data.append(list(map(int, input().split())))
    for j in range(N):
        if data[i][j] != 0:
            start.append([data[i][j], 0, i, j])
start.sort()

global X, Y
S, X, Y = map(int, input().split())
# X - 1, Y - 1 로 생각하고 풀어야함 (좌표 기준 통일)

from collections import deque
q = deque()
for s in start:
    q.append(s)

virus = 0
s = 0

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def solution():
    global virus, s
    while q:
        now = q.popleft()
        virus, s, vx, vy = now[0], now[1], now[2], now[3]
        if vx == X - 1 and vy == Y - 1 and virus != 0:
            return virus
        # 종료조건
        if s == S:
            return 0
        for d in range(4):
            x, y = vx + dr[d], vy + dc[d]
            if x >= 0 and x < N and y >= 0 and y < N:
                if data[x][y] == 0:
                    data[x][y] = virus
                    q.append([virus, s + 1, x, y])
            if x == X - 1 and y == Y - 1:
                return virus

print(solution())
import sys
input = sys.stdin.readline

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
safe = []

# board는 함수 인자로 안넘겨줘도 괜찮나?
def spread(i, j):
    for d in range(4):
        x, y = i + dr[d], j + dc[d]
        if x >= 0 and x < N and y >= 0 and y < M:
            if tmp[x][y] == 0:
                tmp[x][y] = 2
                spread(x, y)

def calcul_safe():
    safe_num = 0
    for i in range(N):
        for j in range(M):
            if tmp[i][j] == 0:
                safe_num += 1
    return safe_num

def dfs(count):
    global safe
    if count == 3:
        # 바이러스 퍼짐
        # 각 바이러스 자리에서 퍼뜨려야함
        for i in range(N):
            for j in range(M):
                tmp[i][j] = board[i][j]
        for p in virus_position:
            spread(p[0], p[1])
        # 안전영역 갯수 세기
        safe = max(safe, calcul_safe())
        return
    # 벽 3개 세우기
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                board[i][j] = 1
                count += 1
                dfs(count)
                board[i][j] = 0
                count -= 1


N, M = map(int, input().split())
board = []
tmp = [[0] * M for _ in range(N)]
virus = 0
virus_position = []
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(len(line)):
        if line[j] == 2:
            virus += 1
            virus_position.append([i, j])
    board.append(line)
count = 0
safe = 0
dfs(count)
print(safe)
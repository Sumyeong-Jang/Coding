n = int(input())
data = []
for _ in range(n):
    data.append(list(map(int, input().split())))

result = [[0] * n for _ in range(n + 1)]

def calcul(i, j):
    result[i + 1][j] = max(result[i + 1][j], result[i][j] + data[i + 1][j])
    result[i + 1][j + 1] = max(result[i + 1][j + 1], result[i][j] + data[i + 1][j + 1])

result[0][0] = data[0][0]
for i in range(n - 1):
    for j in range(i + 1):
        calcul(i, j)
    #print(i + 1, ':', result[i + 1])

print(max(result[n - 1]))
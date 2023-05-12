import sys
input = sys.stdin.readline

N, K = map(int, input().split())
score = list(map(int, input().split()))

for _ in range(K):
    A, B = map(int, input().split())
    s = 0
    for i in range(A - 1, B):
        s += score[i]
    print("{:.2f}".format(s / (B - A + 1)))

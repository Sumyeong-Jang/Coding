import sys
input = sys.stdin.readline

N = int(input())
num = []
while N > 0:
    num.append(N % 10)
    N //= 10

left, right = 0, 0
for i in range(len(num) // 2):
    right += num[i]
    left += num[len(num) - i - 1]

if left == right:
    print('LUCKY')
else:
    print('READY')
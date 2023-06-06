N = int(input())
num = []
while N > 0:
    num.append(N % 10)
    N //= 10
num.reverse()

l, r = 0, 0
for i in range(len(num) // 2):
    l += num[i]
    r += num[len(num) - i - 1]

if l == r:
    print("LUCKY")
else:
    print("READY")
N = int(input())
num = list(map(int, input().split()))
oper_num = list(map(int, input().split()))

o = []

result = []
def calcul(oper):
    global result
    answer = num[0]
    for i in range(N - 1):
        if oper[i] == '+':
            answer += num[i + 1]
        elif oper[i] == '-':
            answer -= num[i + 1]
        elif oper[i] == '*':
            answer *= num[i + 1]
        elif oper[i] == '/':
            if answer < 0:
                answer *= -1
                answer //= num[i + 1]
                answer *= -1
            else:
                answer //= num[i + 1]
    result.append(answer)

def make_oper(n):
    global oper
    sum = oper_num[0] + oper_num[1] + oper_num[2] + oper_num[3]
    if sum == 0:
        calcul(o)
        return

    if n == -1:
        for i in range(4):
            make_oper(i)

    if n == 0:
        if oper_num[0] != 0:
            o.append('+')
            oper_num[0] -= 1
            make_oper(-1)
            o.pop()
            oper_num[0] += 1
        else:
            return

    if n == 1:
        if oper_num[1] != 0:
            o.append('-')
            oper_num[1] -= 1
            make_oper(-1)
            o.pop()
            oper_num[1] += 1
        else:
            return

    if n == 2:
        if oper_num[2] != 0:
            o.append('*')
            oper_num[2] -= 1
            make_oper(-1)
            o.pop()
            oper_num[2] += 1
        else:
            return

    if n == 3:
        if oper_num[3] != 0:
            o.append('/')
            oper_num[3] -= 1
            make_oper(-1)
            o.pop()
            oper_num[3] += 1
        else:
            return

make_oper(-1)
print(max(result))
print(min(result))
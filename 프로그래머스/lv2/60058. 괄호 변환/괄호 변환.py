def seperate(p):
    balance = 0
    idx = 0
    u, v = '', ''
    for i in range(len(p)):
        if p[i] == '(':
            balance += 1
        elif p[i] == ')':
            balance -= 1
        u = u + p[i]
        if balance == 0:
            idx = i
            break
    for i in range(idx + 1, len(p)):
        v = v + p[i]
    return u, v


def right(u):
    check = 0
    for p in u:
        if p == '(':
            check += 1
        elif p == ')':
            if check == 0:
                return False
            else:
                check -= 1
    if check == 0:
        return True
    else:
        return False


def reverse(u):
    ret = ''
    for i in range(1, len(u) - 1):
        if u[i] == '(':
            ret = ret + ')'
        else:
            ret = ret + '('
    return str(ret)


def solution(p):
    answer = ''
    if p == '':
        return str('')
    if right(p):
        return str(p)

    # 문자열 분리 w = u(균형잡힌) + v(비어있어도 됨)
    u, v = seperate(p)

    # u가 (올바른)이면
    if right(u):
        answer = u + solution(v)

    # u가 (올바른)이 아니라면
    if not right(u):
        answer = '(' + solution(v) + ')' + reverse(u)

    return str(answer)
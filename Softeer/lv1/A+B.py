import sys

tc = int(input())
for i in range(tc):
    input_str = input().split()
    A, B = int(input_str[0]), int(input_str[1])
    print('Case #' + str(i + 1) + ':', A + B)

def solution(arr):
    answer = 0
    s = 0
    
    print(len(arr))
    for i in range(len(arr)):
        s += arr[i]
    answer = s / len(arr)
    
    return answer
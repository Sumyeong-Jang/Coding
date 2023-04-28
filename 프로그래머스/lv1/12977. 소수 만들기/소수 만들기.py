def solution(nums):
    answer = 0

    for i in range(len(nums) - 2):
        for j in range(i + 1, len(nums) - 1):
            for k in range(j + 1, len(nums)):
                if is_snum(nums[i] + nums[j] + nums[k]) == 1:
                    answer = answer + 1
                    print(nums[i] + nums[j] + nums[k])
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    print(answer)

    return answer

def is_snum(n):
    i = n - 1
    while (i > 1):
        if n % i == 0:
            return 0
        i = i - 1
    return 1
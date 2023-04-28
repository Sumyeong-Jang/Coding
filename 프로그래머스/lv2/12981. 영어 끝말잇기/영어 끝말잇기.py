def solution(n, words):
    answer = []
    player = [0 for i in range(n + 1)]
    in_words = []
    
    for i in range(len(words)):
        if i == 0:
            in_words.append(words[i])
            player[1] = player[1] + 1
            last = words[i][-1]
        else:
            num = (i % n) + 1
            player[num] = player[num] + 1
            if last != words[i][0]:
                return [num, player[num]]
            elif len(words[i]) == 1:
                return [num, player[num]]
            elif words[i] in in_words:
                return [num, player[num]]
            else:
                in_words.append(words[i])
                last = words[i][-1]
                print(words[i], player[num], last)
    
    #print(player)
    return [0, 0]
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
room = {}
room_table = [[0] * 19 for _ in range(N)]

room_name = []
for _ in range(N):
    room_name.append(input())
room_name.sort()
for i in range(N):
    room[room_name[i].strip()] = i
    room_table[i][18] = 1
for _ in range(M):
    name, start, end = map(str, input().split())
    for i in range(int(start), int(end)):
        room_table[room[name]][i] = 1

for name in room:
    room_id = room[name]
    timetable = []
    flag = 1
    print('Room ' + name + ':')
    for i in range(9, 19):
        if flag != room_table[room_id][i]:
            timetable.append(i)
            flag = room_table[room_id][i]
    for i in range(len(timetable)):
        if timetable[i] // 10 == 0:
            timetable[i] = '0' + str(timetable[i])
        else:
            timetable[i] = str(timetable[i])

    if len(timetable) == 0:
        print('Not available')
    else:
        print(len(timetable)//2, 'available:')
        for i in range(len(timetable) // 2):
            print(timetable[i * 2] + '-' + timetable[i * 2 + 1])
    if len(room) - 1 != room_id:
        print('-----')

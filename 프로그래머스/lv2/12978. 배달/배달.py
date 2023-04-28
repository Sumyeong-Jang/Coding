import heapq

def solution(N, road, K):
    answer = 0

    roadmap = [[] * N for _ in range(N + 1)]
    """
    for i in range(len(road)):
        roadmap[road[i][0]][road[i][1]] = road[i][2]
        roadmap[road[i][1]][road[i][0]] = road[i][2]
    """
    for r in road:
        roadmap[r[0]].append([r[2], r[1]])
        roadmap[r[1]].append([r[2], r[0]])
    
    dist = [float('inf')] * (N + 1)
    dist[1] = 0
    
    dijkstra(roadmap, dist);
    
    for d in dist:
        if d <= K:
            answer = answer + 1
    """
    for i in range(1, len(dist)):
        if dist[i] <= K:
            answer = answer + 1
    """
    print(answer)
    return answer

def dijkstra(roadmap, dist):
    heap = []
    heapq.heappush(heap, [0, 1])
    while heap:
        cost, node = heapq.heappop(heap)
        for c, n in roadmap[node]:
            if cost + c < dist[n]:
                dist[n] = cost + c
                heapq.heappush(heap, [cost + c, n])
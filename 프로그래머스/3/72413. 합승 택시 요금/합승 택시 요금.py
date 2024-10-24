import heapq

def dijkstra(n, start, graph):
    dist = [float('inf')] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]  # (cost, node)

    while pq:
        current_cost, node = heapq.heappop(pq)

        if current_cost > dist[node]:
            continue

        for neighbor, cost in graph[node].items():
            new_cost = current_cost + cost
            if new_cost < dist[neighbor]:
                dist[neighbor] = new_cost
                heapq.heappush(pq, (new_cost, neighbor))

    return dist

def solution(n, s, a, b, fares):
    graph = [{} for _ in range(n + 1)]

    for fare in fares:
        u, v, w = fare
        graph[u][v] = w
        graph[v][u] = w

    dist_from_s = dijkstra(n, s, graph)
    dist_from_a = dijkstra(n, a, graph)
    dist_from_b = dijkstra(n, b, graph)

    answer = float('inf')
    for i in range(1, n + 1):
        answer = min(answer, dist_from_s[i] + dist_from_a[i] + dist_from_b[i])

    return answer

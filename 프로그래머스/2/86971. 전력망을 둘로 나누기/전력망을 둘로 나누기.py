from collections import deque

def solution(n, wires):
    def bfs(start, graph, visited):
        queue = deque([start])
        visited[start] = True
        count = 1
        
        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
                    count += 1
        return count

    graph = {i: [] for i in range(1, n+1)}
    for v1, v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)

    min_difference = float('inf')

    for v1, v2 in wires:
        graph[v1].remove(v2)
        graph[v2].remove(v1)

        visited = [False] * (n + 1)
        count1 = bfs(v1, graph, visited)
        count2 = n - count1

        min_difference = min(min_difference, abs(count1 - count2))

        graph[v1].append(v2)
        graph[v2].append(v1)

    return min_difference

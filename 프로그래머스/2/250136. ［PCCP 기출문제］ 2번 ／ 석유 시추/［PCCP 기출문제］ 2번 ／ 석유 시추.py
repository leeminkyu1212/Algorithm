from collections import deque

def solution(land):
    n = len(land)
    m = len(land[0])
    dy = [0, 0, -1, 1]
    dx = [1, -1, 0, 0]
    visited = [[False] * m for _ in range(n)]

    oil_clusters = [[] for _ in range(m)]

    def bfs(x, y):
        q = deque()
        q.append((x, y))
        visited[x][y] = True
        oil_size = 1
        min_y = y
        max_y = y

        while q:
            cx, cy = q.popleft()
            for k in range(4):
                nx, ny = cx + dx[k], cy + dy[k]
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and land[nx][ny] == 1:
                    visited[nx][ny] = True
                    q.append((nx, ny))
                    oil_size += 1
                    min_y = min(min_y, ny)
                    max_y = max(max_y, ny)

        return min_y, max_y, oil_size

    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                min_y, max_y, oil_size = bfs(i, j)
                for y in range(min_y, max_y + 1):
                    oil_clusters[y].append(oil_size)

    max_oil = 0
    for j in range(m):
        max_oil = max(max_oil, sum(oil_clusters[j]))

    return max_oil

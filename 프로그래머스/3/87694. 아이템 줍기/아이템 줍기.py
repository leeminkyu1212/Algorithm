from collections import deque

def solution(rectangles, characterX, characterY, itemX, itemY):
    board = [[0] * 102 for _ in range(102)]
    for rect in rectangles:
        x1, y1, x2, y2 = map(lambda x: x * 2, rect)
        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                if x1 < i < x2 and y1 < j < y2:
                    board[i][j] = -1 
                elif board[i][j] != -1:
                    board[i][j] = 1

    q = deque([(characterX * 2, characterY * 2)])
    visited = [[False] * 102 for _ in range(102)]
    visited[characterX * 2][characterY * 2] = True
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    distance = 0

    while q:
        for _ in range(len(q)):
            x, y = q.popleft()
            if (x, y) == (itemX * 2, itemY * 2):
                return distance // 2

            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < 102 and 0 <= ny < 102 and not visited[nx][ny] and board[nx][ny] == 1:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        distance += 1

    return -1

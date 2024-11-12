from collections import deque

def solution(board):
    rows, cols = len(board), len(board[0])

    start = goal = None
    for i in range(rows):
        for j in range(cols):
            if board[i][j] == 'R':
                start = (i, j)
            elif board[i][j] == 'G':
                goal = (i, j)

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque([(start[0], start[1], 0)])
    visited = set()
    visited.add(start)

    while queue:
        x, y, moves = queue.popleft()

        if (x, y) == goal:
            return moves

        for dx, dy in directions:
            nx, ny = x, y

            while 0 <= nx + dx < rows and 0 <= ny + dy < cols and board[nx + dx][ny + dy] != 'D':
                nx += dx
                ny += dy

            if (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append((nx, ny, moves + 1))

    return -1

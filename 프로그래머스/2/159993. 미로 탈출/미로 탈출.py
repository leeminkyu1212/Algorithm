def solution(maps):
    from collections import deque

    len_y = len(maps)
    len_x = len(maps[0])

    visited = [[0] * len_x for _ in range(len_y)]

    start = []
    exit = []
    lever = []

    for i in range(len_y):
        for j in range(len_x):
            if maps[i][j] == 'S':
                start = [i, j]
            elif maps[i][j] == 'E':
                exit = [i, j]
            elif maps[i][j] == 'L':
                lever = [i, j]

    directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

    def bfs(start, target):
        q = deque()
        q.append(start)
        visited = [[0] * len_x for _ in range(len_y)]
        visited[start[0]][start[1]] = 1

        while q:
            y, x = q.popleft()
            if [y, x] == target:
                return visited[y][x] - 1

            for dy, dx in directions:
                idy, idx = y + dy, x + dx
                if 0 <= idy < len_y and 0 <= idx < len_x:
                    if maps[idy][idx] != 'X' and visited[idy][idx] == 0:
                        q.append([idy, idx])
                        visited[idy][idx] = visited[y][x] + 1

        return -1 

    distance_to_lever = bfs(start, lever)
    if distance_to_lever == -1:
        return -1

    distance_to_exit = bfs(lever, exit)
    if distance_to_exit == -1:
        return -1

    return distance_to_lever + distance_to_exit

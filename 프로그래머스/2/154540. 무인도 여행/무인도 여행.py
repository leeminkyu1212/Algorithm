from collections import deque

def solution(maps):
    dx = [1, -1, 0, 0]  # 상하좌우 방향 정의
    dy = [0, 0, 1, -1]
    N = len(maps)
    M = len(maps[0])  # 열의 길이도 정의
    visited = [[0 for _ in range(M)] for _ in range(N)]
    answer = []

    queue = deque()
    for i in range(N):
        for j in range(M):
            if maps[i][j] != 'X' and visited[i][j] == 0:
                sum_food = 0
                queue.append([i, j])
                visited[i][j] = 1
                while queue:
                    x, y = queue.popleft()
                    sum_food += int(maps[x][y])
                    for k in range(4):  # 네 방향에 대해 탐색
                        nx = x + dx[k]
                        ny = y + dy[k]

                        if nx < 0 or ny < 0 or nx >= N or ny >= M:
                            continue
                        if maps[nx][ny] == 'X':
                            continue
                        if visited[nx][ny] == 1:
                            continue
                        visited[nx][ny] = 1
                        queue.append([nx, ny])
                answer.append(sum_food)

    if len(answer) == 0:
        return [-1]
    
    answer.sort()
    return answer

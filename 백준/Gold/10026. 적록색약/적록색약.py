import sys
sys.setrecursionlimit(10**6)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

n = int(input())
grid = [list(input()) for _ in range(n)]
visited = []


def dfs(x, y, color):
  visited[x][y] = True
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and grid[nx][
      ny] == color:
      dfs(nx, ny, color)


def cnt():
  global visited

  normal_count = 0
  blind_count = 0
  visited = [[False] * n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      if not visited[i][j]:
        dfs(i, j, grid[i][j])
        normal_count += 1

  for i in range(n):
    for j in range(n):
      if grid[i][j] == 'R':
        grid[i][j] = 'G'

  visited = [[False] * n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      if not visited[i][j]:
        dfs(i, j, grid[i][j])
        blind_count += 1

  return normal_count, blind_count


normal, blind = cnt()
print(normal, blind)

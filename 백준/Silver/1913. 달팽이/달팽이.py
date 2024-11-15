from collections import deque

dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

N = int(input())

map = [[0 for _ in range(N)] for __ in range(N)]

dir_idx = 0
map[0][0] = N ** 2

y, x = [0, 0]
while (1):
  cur_value = map[y][x]
  if cur_value == 1:
    break;
  dy = dir[dir_idx][0] + y
  dx = dir[dir_idx][1] + x

  if 0 <= dy < N and 0 <= dx < N:
    if map[dy][dx] == 0:
      map[dy][dx] = map[y][x] - 1
      y = dy
      x = dx
    else:
      dy -= dir[dir_idx][0]
      dx -= dir[dir_idx][1]
      dir_idx = (dir_idx + 1) % 4
  else:
    dy -= dir[dir_idx][0]
    dx -= dir[dir_idx][1]
    dir_idx = (dir_idx + 1) % 4

find_ = int(input())
keep = []
for y in range(N):
  for x in range(N):
    print(map[y][x], end=' ')
    if map[y][x] == find_:
      keep=[y, x]
  print()

print(keep[0]+1,keep[1]+1)

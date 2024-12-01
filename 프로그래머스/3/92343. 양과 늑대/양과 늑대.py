from collections import defaultdict
from collections import deque
from copy import deepcopy

is_wolf = list()
num2edges = defaultdict(list)
max_sheep = 0


def find_max_recursive(current_loc, used, nsheep, nwolf, can_go):
  global max_sheep

  if used[current_loc] == True:
    return
  used[current_loc] = True

  if is_wolf[current_loc]:
    nwolf += 1
  else:
    nsheep += 1
    max_sheep = max(max_sheep, nsheep)

  if nsheep <= nwolf: return

  can_go.extend(num2edges[current_loc])
  for next_loc in can_go:
    find_max_recursive(next_loc, deepcopy(used), nsheep, nwolf,
                       can_go=[loc for loc in can_go if
                               loc != next_loc and not used[loc]])


def solution(info, edges):
  global is_wolf, num2edges, max_sheep
  is_wolf = info
  used = [False] * len(is_wolf)

  for e_from, e_to in edges:
    num2edges[e_from].append(e_to)
  find_max_recursive(0, used, 0, 0, [])
  return max_sheep

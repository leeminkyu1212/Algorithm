n = int(input())


def quadrant(x, y):
  if x > 0 and y > 0:
    return 'Q1'
  elif x < 0 and y > 0:
    return 'Q2'
  elif x < 0 and y < 0:
    return 'Q3'
  elif x > 0 and y < 0:
    return 'Q4'
  else:
    return 'AXIS'


quadrant_dicts = {
  'Q1': 0,
  'Q2': 0,
  'Q3': 0,
  'Q4': 0,
  'AXIS': 0
}

for i in range(1, n + 1):
  x, y = map(int, input().split())
  quadrant_dicts[quadrant(x, y)] += 1

for i in quadrant_dicts:
  print(f"{i}: {quadrant_dicts[i]}")

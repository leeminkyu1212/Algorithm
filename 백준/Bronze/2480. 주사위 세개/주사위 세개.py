def prize(x, y, z):
  if x == y == z:
    return 10000 + x * 1000
  if x == y or x == z:
    return 1000 + x * 100
  if y == z:
    return 1000 + y * 100
  return max(x, y, z) * 100


dices = list(map(int, input().split()))

print(prize(*dices))

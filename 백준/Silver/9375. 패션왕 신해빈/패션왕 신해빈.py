def prod(dict):
  sum = 1
  for x in cloth_dict.values():
    sum *= (x + 1)
  return sum


T = int(input())
for _ in range(T):
  cloth_dict = {}
  n = int(input())
  for _ in range(n):
    name, category = input().split()
    if cloth_dict.get(category) is not None:
      cloth_dict[category] += 1
    else:
      cloth_dict[category] = 1
  print(prod(cloth_dict) - 1)

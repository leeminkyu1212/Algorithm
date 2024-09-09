T = int(input())

for _ in range(T):
  expressions = list(input().split())
  value = float(expressions[0])
  for expression in expressions[1:]:
    if (expression == '@'):
      value *= 3
    elif (expression == '%'):
      value += 5
    elif (expression == '#'):
      value -= 7
  print(f"{value:.2f}")

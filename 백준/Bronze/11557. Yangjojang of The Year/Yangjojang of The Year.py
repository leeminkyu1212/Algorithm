T = int(input())

for _ in range(T):
  Max = {
    'univ': None,
    'drink': 0
  }
  N = int(input())
  for _ in range(N):
    univ, drink = (input()).split()
    if (int(drink) > Max['drink']):
      Max['univ'] = univ
      Max['drink'] = int(drink)
  print(Max['univ'])

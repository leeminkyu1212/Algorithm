import math

M = int(input())
N = int(input())

list1 = [x for x in range(M, N + 1) if math.sqrt(x).is_integer()]

if (list1 != []):
  print(sum(list1))
  print(list1[0])
else:
  print(-1)

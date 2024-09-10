K, N, M = map(int, input().split())

need_money = K * N - M
if (need_money <= 0):
  print(0)
else:
  print(need_money)

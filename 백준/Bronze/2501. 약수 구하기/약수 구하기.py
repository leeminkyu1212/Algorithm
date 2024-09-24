N, K = map(int, input().split())

div_list = [x for x in range(1, N // 2 + 1) if N % x == 0]
div_list.append(N)
if len(div_list) >= K:
  print(div_list[K-1])
else:
  print(0)

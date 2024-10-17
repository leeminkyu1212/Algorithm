N, K = map(int, (input().split()))

ans = 0
for t in range(0, N + 1):
  for m in range(0, 60):
    for s in range(0, 60):
      time_str = str(t) + str(m) + str(s)
      if t < 10 or m < 10 or s < 10: time_str += '0'
      if str(K) in time_str:
        ans += 1

print(ans)

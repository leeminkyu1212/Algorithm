num_list = [1, 2, 3]


def dfs(sum, n):
  global ans
  if (sum == n):
    ans += 1
    return
  for num in num_list:
    if (sum + num > n):
      continue
    sum += num
    dfs(sum, n)
    sum -= num


T = int(input())

for _ in range(T):
  ans = 0
  n = int(input())
  dfs(0, n)
  print(ans)

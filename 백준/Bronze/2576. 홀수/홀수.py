new_list = []
min_num = 2e9
for _ in range(7):
  N = int(input())
  if N % 2 != 0:
    new_list.append(N)
    if (N < min_num):
      min_num = N

if len(new_list) == 0:
  print(-1)

else:
  print(sum(new_list))
  print(min_num)

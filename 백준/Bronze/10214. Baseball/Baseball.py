T = int(input())

for _ in range(T):
  list_yk = [0, 0]
  for i in range(9):
    Y, K = map(int, input().split())
    list_yk[0] += Y
    list_yk[1] += K

  if list_yk[0] > list_yk[1]:
    print("Yonsei")
  elif list_yk[0] < list_yk[1]:
    print("Korea")
  else:
    print("Draw")

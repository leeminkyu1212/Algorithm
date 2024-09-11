N = int(input())


def advice(r, e, c):
  if (e - c > r):
    print("advertise")
  elif (e - c == r):
    print("does not matter")
  else:
    print("do not advertise")


for _ in range(N):
  TGN = list(map(int, input().split()))
  advice(*TGN)

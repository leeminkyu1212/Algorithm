A = int(input())
B = int(input())

listB = list(map(int, str(B)))
listB.reverse()
for b in listB:
  print(A * b)

print(A * B)

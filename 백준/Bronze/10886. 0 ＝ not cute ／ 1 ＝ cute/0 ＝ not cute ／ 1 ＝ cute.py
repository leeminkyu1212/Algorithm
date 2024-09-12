N = int(input())
sum = 0
for _ in range(N):
  vote = int(input())
  if vote == 0: vote = -1
  sum += vote

if (sum < 0):
  print("Junhee is not cute!")
else:
  print("Junhee is cute!")

import sys

N=int(sys.stdin.readline().rstrip())
sum=0
for _ in range(N):
  num=int(sys.stdin.readline().rstrip())
  sum+=num


print(sum-N+1)
T=int(input())

for _ in range(T):
  s=int(input())
  n=int(input())
  sum=s
  for _ in range(n):
    q,p=map(int,input().split())
    sum+=q*p
  print(sum)
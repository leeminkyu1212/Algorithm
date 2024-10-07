def dice(i):
  x,y=map(int,input().split())
  print(f"Case {i}: {x+y}")

N=int(input())

for i in range(1,N+1):
  dice(i)
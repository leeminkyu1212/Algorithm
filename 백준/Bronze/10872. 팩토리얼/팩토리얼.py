
def factorial(N):
  result=1
  for i in range(1,N+1):
    result*=i
  print(result)


N=int(input())

factorial(N)
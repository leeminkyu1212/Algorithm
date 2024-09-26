def combination(n,m):
  sum=1
  for i in range(n,n-m,-1):
    sum*=i
  for i in range(m,0,-1):
    sum//=i
  return sum


n, m = map(int, input().split())
print(combination(n,m))
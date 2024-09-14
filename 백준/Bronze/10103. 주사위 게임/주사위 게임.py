n = int(input())

changyoung = 100
sangduck = 100

for _ in range(n):
  A, B = map(int, input().split())
  if A < B:
    changyoung -= B
  elif A > B:
    sangduck -= A

print(changyoung)
print(sangduck)

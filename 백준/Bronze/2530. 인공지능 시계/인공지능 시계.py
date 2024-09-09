A, B, C = map(int, input().split())

D = int(input())

C = A * 3600 + B * 60 + C + D

A = (C // 3600) % 24
B = (C // 60) % 60
C = C % 60

print(f"{A} {B} {C}")

def solution(n):
    a, b = 1, 2
    for i in range(3, n + 1):
        a, b = b, (a + b) % 1234567
    return a if n == 1 else b


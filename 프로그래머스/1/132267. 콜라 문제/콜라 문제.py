def solution(a, b, n):
    total_cola = 0
    
    while n >= a:
        new_cola = (n // a) * b
        total_cola += new_cola
        n = (n % a) + new_cola
    
    return total_cola

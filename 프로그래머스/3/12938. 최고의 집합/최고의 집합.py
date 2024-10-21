def solution(n, s):
    if s < n:
        return [-1]
    
    quotient = s // n
    remainder = s % n
    
    result = [quotient] * n
    for i in range(remainder):
        result[-(i + 1)] += 1
    
    return result

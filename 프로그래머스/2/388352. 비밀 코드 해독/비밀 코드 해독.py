from itertools import combinations

def solution(n, q, ans):
    codes = list(combinations(range(1, n+1), 5))
    
    count = 0
    for code in codes:
        is_valid = True
        for i in range(len(q)):
            match_count = len(set(code) & set(q[i]))
            if match_count != ans[i]:
                is_valid = False
                break
        if is_valid:
            count += 1

    return count

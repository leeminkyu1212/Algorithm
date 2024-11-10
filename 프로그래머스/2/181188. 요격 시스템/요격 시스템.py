def solution(targets):
    targets.sort()
    
    missiles = 0
    missile_end = -1
    
    for start, end in targets:
        if start >= missile_end:
            missiles += 1
            missile_end = end  
        else:
            missile_end = min(missile_end, end)
    
    return missiles

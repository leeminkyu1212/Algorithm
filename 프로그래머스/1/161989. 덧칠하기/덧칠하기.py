def solution(n, m, section):
    
    end=0
    
    answer = 0
    
    for block in section:
        if end<block:
            end=block+m-1
            answer+=1
        else:
            continue
        if end>=n:
            break
        
        
    return answer
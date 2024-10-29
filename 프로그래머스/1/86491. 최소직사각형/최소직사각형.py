def solution(sizes):
    
    max_x=-1
    max_y=-1
    
    for size in sizes:
        size.sort()
        x=size[0]
        y=size[1]
        max_x=max(max_x,x)
        max_y=max(max_y,y)
    
    
        
    answer = max_x*max_y
    return answer
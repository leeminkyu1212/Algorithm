def solution(k, dungeons):
    
    length=len(dungeons)
    
    visited=[0 for _ in range(length)]
    
    max_level=0
    def func(k,level):
        nonlocal max_level
        for i in range(length):
            if visited[i]==1:
                continue
            elif k>=dungeons[i][0]:
                k-=dungeons[i][1]
                visited[i]=1
                func(k,level+1)
                k+=dungeons[i][1]
                visited[i]=0
        max_level=max(max_level,level)
                
    func(k,0)
    
    
    return max_level
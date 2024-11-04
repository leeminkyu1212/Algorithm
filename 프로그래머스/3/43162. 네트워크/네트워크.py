import sys
sys.setrecursionlimit(10000000)
def solution(n, computers):
    
    visited=[0 for _ in range(n)]
    
    count=0
    
    def dfs(start):
        
        for i in range(n):
            if i==start: continue
            if visited[i]==1: continue
            if computers[start][i]==1:
                visited[i]=1
                dfs(i)
            
    
    for i in range(n):
        if visited[i]==0:
            visited[i]=1
            dfs(i)
            count+=1
    
    
        
    
    
    return count
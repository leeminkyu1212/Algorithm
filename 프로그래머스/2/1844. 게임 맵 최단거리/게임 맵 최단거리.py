from collections import deque

def solution(maps):
    
    n=len(maps)
    m=len(maps[0])
    
    dy=[1,0,0,-1]
    dx=[0,1,-1,0]
    min_visit=list([1e10 for _ in range(m)] for __ in range(n))
    min_visit[0][0]=0
    
    q=deque()
    q.append([0,0])
    while(len(q)!=0):
        list1=q.popleft()
        y=list1[0]
        x=list1[1]
        for i in range(4):
            idy=y+dy[i]
            idx=x+dx[i]
            
            if 0<=idy<n and 0<=idx<m:
                if min_visit[idy][idx]<=min_visit[y][x]+1:
                    continue
                if maps[idy][idx]==0:
                    continue
                q.append([idy,idx])
                min_visit[idy][idx]=min_visit[y][x]+1
    if min_visit[n-1][m-1]==1e10:
        return -1
    return min_visit[n-1][m-1]+1
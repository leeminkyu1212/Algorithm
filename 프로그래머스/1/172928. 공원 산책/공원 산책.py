def solution(park, routes):
    
    row=len(park)
    col=len(park[0])
    
    for i in range(row):
        for j in range(col):
            if park[i][j]=='S':
                start=[i,j]

                
    def move(now,dir,cnt):
        dy,dx=now
        if dir=='N':
            for i in range(cnt):
                now[0]-=1
                y,x=now
                if y<0 or park[y][x]=='X':
                    return [dy,dx]
        elif dir=='S':
            for i in range(cnt):
                now[0]+=1
                y,x=now
                if y>=row or park[y][x]=='X':
                    return [dy,dx]
        elif dir=='W':
            for i in range(cnt):
                now[1]-=1
                y,x=now
                if x<0 or park[y][x]=='X':
                    return [dy,dx]
        elif dir=='E':
            for i in range(cnt):
                now[1]+=1
                y,x=now
                if x>=col or park[y][x]=='X':
                    return [dy,dx]
        return now
    def func(now,route):
        y,x=now
        dir,cnt=route.split()
        cnt=int(cnt)
        now=move(now,dir,cnt)
        return now
    for route in routes:
        start=func(start,route)
    
    
    return start
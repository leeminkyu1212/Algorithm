def solution(priorities, location):
    from collections import deque

    arr=deque()
    for idx,priorities in enumerate(priorities):
        arr.append([priorities,idx])
    
    def func(now,arr_cur):
        
        for cur in arr_cur:
            if cur[0]>now[0]:
                return False
        return True
    
    new_arr=[]    
    while arr:
        now=arr.popleft()
        if func(now,arr)==True:
            new_arr.append(now)
            if now[1]==location:
                return len(new_arr)
        else:
            arr.append(now)
                
            
        

def solution(triangle):
    
    
    height=len(triangle)
    
    for level in range(height-2,-1,-1):
        for idx in range(len(triangle[level])):
            triangle[level][idx]+=max(triangle[level+1][idx],triangle[level+1][idx+1])
            
    answer=triangle[0][0]
    return answer
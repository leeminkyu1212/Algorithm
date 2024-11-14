def solution(m, n, startX, startY, balls):
    answer = []
    start = [startX, startY]
    for end in balls:
        temp_dist = []
        
        if not (start[0] == end[0] and start[1] < end[1]):
            dist = (start[0] - end[0]) ** 2 + (2 * n - start[1] - end[1]) ** 2
            temp_dist.append(dist)
        
        if not (start[0] == end[0] and start[1] > end[1]):
            dist = (start[0] - end[0]) ** 2 + (start[1] + end[1]) ** 2
            temp_dist.append(dist)
        
        if not (start[1] == end[1] and start[0] > end[0]):
            dist = (start[0] + end[0]) ** 2 + (start[1] - end[1]) ** 2
            temp_dist.append(dist)
        
        if not (start[1] == end[1] and start[0] < end[0]):
            dist = (2 * m - start[0] - end[0]) ** 2 + (start[1] - end[1]) ** 2
            temp_dist.append(dist)
        
        answer.append(min(temp_dist))
    
    return answer

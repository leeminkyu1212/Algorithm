def solution(brown, yellow):
    area=brown+yellow
    
    for i in range(3,area//2):
        outside_y=i
        outside_x=area//i
        if outside_y>outside_x:
            continue
        if (outside_x-2)*(outside_y-2)==yellow:
            return([outside_x,outside_y])

def solution(array, commands):

    answer = []
    
    for command in commands:
        new_list=array[command[0]-1:command[1]]
        new_list.sort()
        answer.append(new_list[command[2]-1])
    
    
    
    
    return answer
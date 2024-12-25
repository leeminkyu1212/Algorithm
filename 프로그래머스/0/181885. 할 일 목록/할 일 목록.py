def solution(todo_list, finished):
    answer=[]
    for x,y in zip(todo_list,finished):
        if y==False:
            answer.append(x)
    return answer
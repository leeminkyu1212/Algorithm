def solution(arr):
    answer=[]
    for prev,now in zip(arr,arr[1:]):
        if prev==now:
            continue
        else : answer.append(prev)
    
    answer.append(arr[-1])

    return answer
def solution(rny_string):
    answer=''
    for char in rny_string:
        if char=='m':
            answer+='rn'
        else:answer+=char
        
    return answer
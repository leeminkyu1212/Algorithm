def solution(q, r, code):
    answer = ''
    for char in code[r::q]:
        answer+=char
        
    return answer
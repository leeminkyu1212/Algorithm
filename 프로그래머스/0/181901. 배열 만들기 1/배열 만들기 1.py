def solution(n, k):
    answer = []
    i=1
    while True:
        if i*k>n:
            break
        answer.append(k*i)
        i+=1
    return answer
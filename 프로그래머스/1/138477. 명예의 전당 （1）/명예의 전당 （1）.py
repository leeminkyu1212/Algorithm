def solution(k, score):
    
    from heapq import heappush,heappop
        
    heap=[]
    answer=[]
    for i in range(len(score)):
        heappush(heap,-score[i])
        if i<k:
            answer.append(-max(heap))
        else:
            list_k=[]
            for i in range(k):
                list_k.append(heappop(heap))
            answer.append(-list_k[-1])
            for i in range(k):
                heappush(heap,list_k[i])
    return answer
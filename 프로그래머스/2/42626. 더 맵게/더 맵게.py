
def solution(scoville, K):
    import heapq
    heapq.heapify(scoville)
    cnt=0
    while scoville[0]<K:
        if len(scoville)==1:
            return -1
        cnt+=1
        min_0=heapq.heappop(scoville)
        min_1=heapq.heappop(scoville)
        heapq.heappush(scoville,min_0+min_1*2)
    
    return cnt
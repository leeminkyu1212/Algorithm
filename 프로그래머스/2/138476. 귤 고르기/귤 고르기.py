def solution(k, tangerine):
    from collections import defaultdict
    answer=0    
    tan_dict=defaultdict(int)
    for tan in tangerine:
        tan_dict[tan]+=1
    
    tan_sorted=dict(sorted(tan_dict.items(),key=lambda x: x[1],reverse=True))
    
    for key in tan_sorted:
        
        k-=tan_sorted[key]
        answer+=1
        if k<=0:
            return answer
    

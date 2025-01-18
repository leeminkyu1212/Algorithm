def solution(lottos, win_nums):
    matched = len(set(lottos) & set(win_nums))
    
    zero_count = lottos.count(0)
    max_rank = min(7 - (matched + zero_count), 6)
    min_rank = min(7 - matched, 6)
    
    return [max_rank, min_rank]

def solution(clothes):
    cloth_dict = {}
    
    for cloth, kind in clothes:
        cloth_dict.setdefault(kind, []).append(cloth)
    
    ways = 1
    for kind, items in cloth_dict.items():
        ways *= (len(items) + 1)
    
    return ways - 1

def solution(num_list):
    from math import prod
    if len(num_list)>10:
        return sum(num_list)
    else:
        return prod(num_list)
    return answer
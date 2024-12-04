def solution(data, col, row_begin, row_end):
    data.sort(key=lambda x: (x[col - 1], -x[0]))
    
    s_list = []
    for i in range(row_begin, row_end + 1):
        s_list.append(sum(x % i for x in data[i - 1]))
    
    answer = s_list[0]
    for s_i in s_list[1:]:
        answer ^= s_i
    
    return answer

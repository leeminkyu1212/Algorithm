def solution(sequence, k):
    n = len(sequence)
    left, right = 0, 0
    current_sum = sequence[0]
    min_length = float('inf')
    result = [0, 0]
    
    while right < n:
        if current_sum == k:
            if (right - left) < min_length:
                min_length = right - left
                result = [left, right]
            elif (right - left) == min_length and left < result[0]:
                result = [left, right]
                
            current_sum -= sequence[left]
            left += 1
            
        elif current_sum < k:
            right += 1
            if right < n:
                current_sum += sequence[right]
                
        else:
            current_sum -= sequence[left]
            left += 1

    return result

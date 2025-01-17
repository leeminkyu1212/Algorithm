def solution(s, skip, index):
    valid_chars = [chr(i) for i in range(ord('a'), ord('z') + 1) if chr(i) not in skip]
    
    result = []
    
    for char in s:
        current_idx = valid_chars.index(char)
        new_idx = (current_idx + index) % len(valid_chars)
        result.append(valid_chars[new_idx])
    
    return ''.join(result)

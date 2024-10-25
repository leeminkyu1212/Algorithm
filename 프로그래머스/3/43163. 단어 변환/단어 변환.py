from collections import deque

def solution(begin, target, words):
    if target not in words:
        return 0
    
    # 단어 변환이 가능한지 체크하는 함수
    def can_convert(word1, word2):
        count = sum([1 for a, b in zip(word1, word2) if a != b])
        return count == 1
    
    queue = deque([(begin, 0)])
    visited = set([begin])
    
    while queue:
        current_word, steps = queue.popleft()
        
        if current_word == target:
            return steps
        
        for word in words:
            if word not in visited and can_convert(current_word, word):
                visited.add(word)
                queue.append((word, steps + 1))
    
    return 0


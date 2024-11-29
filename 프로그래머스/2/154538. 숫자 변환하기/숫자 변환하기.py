from collections import deque

def solution(x, y, n):
    if x == y:
        return 0  # 이미 같은 값이면 연산 필요 없음
    
    queue = deque([(x, 0)])  # (현재 값, 연산 횟수)
    visited = set([x])       # 방문한 값 저장

    while queue:
        current, level = queue.popleft()
        
        # 가능한 다음 상태 계산
        for next_val in [current + n, current * 2, current * 3]:
            if next_val == y:
                return level + 1
            if next_val < y and next_val not in visited:
                visited.add(next_val)
                queue.append((next_val, level + 1))
    
    return -1  # 목표 값에 도달할 수 없는 경우

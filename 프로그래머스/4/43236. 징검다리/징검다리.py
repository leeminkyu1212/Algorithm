def solution(distance, rocks, n):
    rocks.sort()
    rocks = [0] + rocks + [distance]
    
    left, right = 1, distance
    answer = 0

    while left <= right:
        mid = (left + right) // 2
        remove_count = 0
        prev = 0
        min_distance = 1e11
        
        for rock in rocks[1:]:
            if rock - prev < mid:
                remove_count += 1
            else:
                min_distance = min(min_distance, rock - prev)
                prev = rock

        if remove_count > n:
            right = mid - 1
        else:
            answer = min_distance
            left = mid + 1

    return answer
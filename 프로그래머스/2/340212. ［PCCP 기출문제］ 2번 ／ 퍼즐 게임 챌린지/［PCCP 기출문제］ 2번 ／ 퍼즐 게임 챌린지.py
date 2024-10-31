def solution(diffs, times, limit):
    def can_solve_in_time(level):
        total_time = 0
        total_time += times[0]
        
        for i in range(1, len(diffs)):
            diff = diffs[i]
            time_cur = times[i]
            time_prev = times[i - 1]
            
            if level >= diff:
                total_time += time_cur
            else:
                fail_count = diff - level
                total_time += (time_cur + time_prev) * fail_count + time_cur
            
            if total_time > limit:
                return False
        return True

    left, right = 1, max(diffs)
    answer = right

    while left <= right:
        mid = (left + right) // 2
        if can_solve_in_time(mid):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer

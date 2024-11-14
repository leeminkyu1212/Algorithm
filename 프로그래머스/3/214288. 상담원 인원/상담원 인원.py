def solution(k, n, reqs):
    from heapq import heappush, heappop
    from collections import defaultdict

    # 대기 시간 계산 함수
    def calculate_wait_time(mentor_num):
        waiting_time = 0
        q_list = [[] for _ in range(k)]
        
        for req in reqs:
            start_time, duration, mentor_idx = req
            mentor_idx -= 1  # 멘토 인덱스 조정
            
            if len(q_list[mentor_idx]) < mentor_num[mentor_idx]:
                heappush(q_list[mentor_idx], start_time + duration)
            else:
                earliest_end_time = heappop(q_list[mentor_idx])
                
                if earliest_end_time > start_time:
                    waiting_time += earliest_end_time - start_time
                    heappush(q_list[mentor_idx], earliest_end_time + duration)
                else:
                    heappush(q_list[mentor_idx], start_time + duration)
        
        return waiting_time

    mentor_num = [1] * k
    remaining_mentors = n - k
    
    for _ in range(remaining_mentors):
        wait_times = []
        for i in range(k):
            mentor_num[i] += 1
            wait_time = calculate_wait_time(mentor_num)
            wait_times.append((wait_time, i))
            mentor_num[i] -= 1
        
        min_wait_time_type = min(wait_times)[1]
        mentor_num[min_wait_time_type] += 1

    return calculate_wait_time(mentor_num)

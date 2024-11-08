def solution(jobs):
    from heapq import heappush, heappop
    jobs.sort()
    
    current_time = 0
    total_time = 0
    job_count = len(jobs)
    waiting_jobs = []
    index = 0

    while index < job_count or waiting_jobs:
        while index < job_count and jobs[index][0] <= current_time:
            heappush(waiting_jobs, (jobs[index][1], jobs[index][0]))
            index += 1

        if waiting_jobs:
            job_duration, job_request_time = heappop(waiting_jobs)
            current_time += job_duration
            total_time += current_time - job_request_time
        else:
            current_time = jobs[index][0]
    
    return total_time // job_count

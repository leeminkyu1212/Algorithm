from datetime import datetime, timedelta

def solution(plans):
    def to_minutes(time_str):
        h, m = map(int, time_str.split(":"))
        return h * 60 + m

    plans.sort(key=lambda x: to_minutes(x[1]))
    
    completed = []
    stack = []

    for i in range(len(plans)):
        name, start_time, playtime = plans[i]
        start_minutes = to_minutes(start_time)
        playtime = int(playtime)
        end_minutes = start_minutes + playtime

        if i + 1 < len(plans):
            next_start_minutes = to_minutes(plans[i + 1][1])
            if end_minutes > next_start_minutes:
                stack.append((name, end_minutes - next_start_minutes))
            else:
                completed.append(name)
                remaining_time = next_start_minutes - end_minutes
                while stack and remaining_time > 0:
                    last_task, last_task_time = stack.pop()
                    if last_task_time <= remaining_time:
                        completed.append(last_task)
                        remaining_time -= last_task_time
                    else:
                        stack.append((last_task, last_task_time - remaining_time))
                        break
        else:
            completed.append(name)
            while stack:
                last_task, _ = stack.pop()
                completed.append(last_task)

    return completed

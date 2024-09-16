def add_zero(x: int) -> str:
    return f"{x:02}"


def remain_time(time_now: list, time_start: list) -> list:
    time_now_second = time_now[0] * 3600 + time_now[1] * 60 + time_now[2]
    time_start_second = time_start[0] * 3600 + time_start[1] * 60 + time_start[2]

    time_remain = (time_start_second - time_now_second) % (24 * 3600)

    hours = time_remain // 3600
    minutes = (time_remain % 3600) // 60
    seconds = time_remain % 60

    return [add_zero(hours), add_zero(minutes), add_zero(seconds)]


time_now = list(map(int, input().split(":")))
time_start = list(map(int, input().split(":")))

print(":".join(remain_time(time_now, time_start)))

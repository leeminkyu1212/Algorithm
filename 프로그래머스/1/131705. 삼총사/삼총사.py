def solution(number):
    answer = 0

    def func(level, sum_num, index):
        nonlocal answer
        if level == 3:
            if sum_num == 0:
                answer += 1
            return
        for j in range(index, len(number)):
            func(level + 1, sum_num + number[j], j + 1)

    func(0, 0, 0)
    return answer

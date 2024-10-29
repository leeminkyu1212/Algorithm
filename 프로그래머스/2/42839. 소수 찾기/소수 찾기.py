import sys
sys.setrecursionlimit(1000000)

# 소수 판별 함수 수정
def is_prime(num):
    if num < 2:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    num_sqrt = int(num**0.5) + 1
    for i in range(3, num_sqrt, 2):
        if num % i == 0:
            return False
    return True

def solution(numbers):
    numbers_len = len(numbers)
    visited = [0] * numbers_len
    number_set = set()

    def dfs(n):
        if n:
            number_set.add(int(n))
        for idx, number in enumerate(numbers):
            if visited[idx] == 1:
                continue
            visited[idx] = 1
            dfs(n + number)
            visited[idx] = 0

    dfs("")

    answer = len([x for x in number_set if is_prime(x)])
    return answer

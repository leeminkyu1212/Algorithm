def solution(my_string):
    numbers = [int(ch) for ch in my_string if ch.isdigit()]
    numbers.sort()
    return numbers

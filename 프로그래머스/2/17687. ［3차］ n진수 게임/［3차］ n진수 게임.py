def solution(n, t, m, p):
    numbers = ""
    result = ""
    current_num = 0

    while len(numbers) < t * m:
        numbers += convert_to_base(current_num, n)
        current_num += 1

    for i in range(t):
        result += numbers[(p - 1) + i * m]

    return result


def convert_to_base(num, base):
    digits = "0123456789ABCDEF"
    if num == 0:
        return "0"

    result = ""
    while num > 0:
        result = digits[num % base] + result
        num //= base

    return result



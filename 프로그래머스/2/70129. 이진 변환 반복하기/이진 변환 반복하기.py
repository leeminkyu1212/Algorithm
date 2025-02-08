def solution(s):
    transform_count = 0
    removed_zeros = 0

    while s != "1":
        removed_zeros += s.count("0")
        s = s.replace("0", "")
        s = bin(len(s))[2:]
        transform_count += 1

    return [transform_count, removed_zeros]


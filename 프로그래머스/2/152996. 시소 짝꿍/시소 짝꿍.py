from collections import Counter

def solution(weights):
    weight_count = Counter(weights)
    result = 0

    ratios = [(1, 1), (2, 3), (3, 4), (1, 2)]

    weights_set = sorted(weight_count.keys())

    for i, weight in enumerate(weights_set):
        count = weight_count[weight]
        result += count * (count - 1) // 2

        for a, b in ratios:
            if a == b:
                continue
            if (weight * b) % a != 0:
                continue
            pair_weight = (weight * b) // a
            if pair_weight > weight and pair_weight in weight_count:
                result += count * weight_count[pair_weight]

    return result

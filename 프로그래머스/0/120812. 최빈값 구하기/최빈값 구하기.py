from collections import Counter

def solution(array):
    freq = Counter(array).most_common()
    max_count = freq[0][1]
    candidates = [val for val, count in freq if count == max_count]
    return candidates[0] if len(candidates) == 1 else -1

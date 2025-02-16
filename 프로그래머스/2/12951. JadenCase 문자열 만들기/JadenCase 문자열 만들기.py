def solution(s):
    words = s.split(" ")
    result = []

    for word in words:
        if word:
            result.append(word[0].upper() + word[1:].lower())
        else:
            result.append("")  # 공백 유지

    return " ".join(result)


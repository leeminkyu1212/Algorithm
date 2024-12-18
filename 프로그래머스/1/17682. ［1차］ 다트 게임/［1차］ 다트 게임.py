def solution(dartResult):
    scores = []

    i = 0
    while i < len(dartResult):
        if dartResult[i] == '1' and i+1 < len(dartResult) and dartResult[i+1] == '0':
            score = 10
            i += 2
        else:
            score = int(dartResult[i])
            i += 1

        bonus = dartResult[i]
        i += 1

        if bonus == 'S':
            score = score ** 1
        elif bonus == 'D':
            score = score ** 2
        elif bonus == 'T':
            score = score ** 3

        if i < len(dartResult) and dartResult[i] in ['*', '#']:
            option = dartResult[i]
            i += 1

            if option == '*':
                score *= 2
                if scores:
                    scores[-1] *= 2
            elif option == '#':
                score *= -1

        scores.append(score)

    return sum(scores)
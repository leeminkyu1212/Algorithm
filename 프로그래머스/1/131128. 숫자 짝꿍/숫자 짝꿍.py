def solution(X, Y):
    X_dict = [0] * 10
    Y_dict = [0] * 10
    friend_list = ""

    for i in X:
        X_dict[int(i)] += 1

    for i in Y:
        Y_dict[int(i)] += 1

    for i in range(9, -1, -1):
        common_count = min(X_dict[i], Y_dict[i])
        friend_list += str(i) * common_count

    if not friend_list:
        return "-1"

    if friend_list[0] == '0':
        return "0"

    return friend_list

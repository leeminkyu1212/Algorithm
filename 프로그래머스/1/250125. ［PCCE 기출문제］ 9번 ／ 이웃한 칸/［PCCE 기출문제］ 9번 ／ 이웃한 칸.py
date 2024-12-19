def solution(board, h, w):
    n = len(board)
    color = board[h][w]
    dh = [0, 1, -1, 0]
    dw = [1, 0, 0, -1]
    return sum(
        0 <= h+dh[i] < n and 0 <= w+dw[i] < n and board[h+dh[i]][w+dw[i]] == color
        for i in range(4)
    )

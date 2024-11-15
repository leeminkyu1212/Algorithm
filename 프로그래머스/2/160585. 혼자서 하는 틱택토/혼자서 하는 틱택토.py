def solution(board):
    def count_turns():
        o_count = sum(row.count('O') for row in board)
        x_count = sum(row.count('X') for row in board)
        return o_count, x_count
    
    def check_winner(player):
        for i in range(3):
            if board[i][0] == board[i][1] == board[i][2] == player:  # 가로
                return True
            if board[0][i] == board[1][i] == board[2][i] == player:  # 세로
                return True
        if board[0][0] == board[1][1] == board[2][2] == player:  # 대각선 1
            return True
        if board[0][2] == board[1][1] == board[2][0] == player:  # 대각선 2
            return True
        return False
    
    o_count, x_count = count_turns()
    
    if not (o_count == x_count or o_count == x_count + 1):
        return 0
    
    o_win = check_winner('O')
    x_win = check_winner('X')
    
    if o_win and x_win:
        return 0
    if o_win and o_count != x_count + 1:
        return 0
    if x_win and o_count != x_count:
        return 0
    
    return 1

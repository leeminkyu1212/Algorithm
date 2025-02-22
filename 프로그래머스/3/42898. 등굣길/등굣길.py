def solution(m, n, puddles):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    grid = [[0] * (m + 1) for _ in range(n + 1)]

    for puddle in puddles:
        x, y = puddle
        grid[y][x] = 1

    dp[1][0] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if grid[i][j] == 1:
                continue
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007

    return dp[n][m]

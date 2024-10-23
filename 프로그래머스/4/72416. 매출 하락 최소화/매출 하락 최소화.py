import sys
sys.setrecursionlimit(300000)

def solution(sales, links):
    n = len(sales)
    tree = [[] for _ in range(n + 1)]
    for a, b in links:
        tree[a].append(b)

    dp = [[0, 0] for _ in range(n + 1)]

    visited = [False] * (n + 1)

    def dfs(node):
        visited[node] = True
        dp[node][0] = 0
        dp[node][1] = sales[node - 1]

        if not tree[node]:
            return

        attend_diff = float('inf')

        for child in tree[node]:
            if not visited[child]:
                dfs(child)
                dp[node][0] += min(dp[child][0], dp[child][1])
                dp[node][1] += min(dp[child][0], dp[child][1])
                attend_diff = min(attend_diff, dp[child][1] - dp[child][0])

        if attend_diff > 0:
            dp[node][0] += attend_diff

    dfs(1)
    return min(dp[1][0], dp[1][1])


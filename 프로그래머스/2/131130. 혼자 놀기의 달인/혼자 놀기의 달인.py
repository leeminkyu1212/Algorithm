def solution(cards):
    visited = [False] * len(cards)
    group_sizes = []
    
    def dfs(node):
        size = 0
        while not visited[node]:
            visited[node] = True
            size += 1
            node = cards[node] - 1
        return size

    for i in range(len(cards)):
        if not visited[i]:
            group_sizes.append(dfs(i))

    group_sizes.sort(reverse=True)
    if len(group_sizes) < 2:
        return 0
    return group_sizes[0] * group_sizes[1]


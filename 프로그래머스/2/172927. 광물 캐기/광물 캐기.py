def solution(picks, minerals):
    def mining(pick, mineral):
        if pick == 0:
            return 1
        if pick == 1:
            return 5 if mineral == 'diamond' else 1
        if pick == 2:
            return 25 if mineral == 'diamond' else (5 if mineral == 'iron' else 1)
    
    length = len(minerals)
    result = 50000
    
    def dfs(index, total, picks_left):
        nonlocal result
        if index >= length or sum(picks_left) == 0:
            result = min(result, total)
            return
        
        for i in range(3):
            if picks_left[i] > 0:
                picks_left[i] -= 1
                current_total = 0
                
                for j in range(5):
                    if index + j >= length:
                        break
                    current_total += mining(i, minerals[index + j])
                
                dfs(index + 5, total + current_total, picks_left)
                picks_left[i] += 1

    dfs(0, 0, picks[:])
    return result

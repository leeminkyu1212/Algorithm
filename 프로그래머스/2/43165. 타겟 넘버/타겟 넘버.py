def solution(numbers, target):
    
    def make_sum(signs):
        total = 0
        for x, y in zip(numbers, signs):
            if y == '-':
                x = -x
            total += x
        return total

    def dfs(signs):
        if len(signs) == len(numbers):
            if make_sum(signs) == target:
                return 1
            return 0

        count = 0
        for sign in ['+', '-']:
            count += dfs(signs + [sign])
        return count

    return dfs([])

memo = {}

def solution(n):
    def generate_parentheses(open_count, close_count):
        if open_count > close_count:
            return 0
        if open_count == 0 and close_count == 0:
            return 1
        if (open_count, close_count) in memo:
            return memo[(open_count, close_count)]
        
        result = 0
        if open_count > 0:
            result += generate_parentheses(open_count - 1, close_count)
        if close_count > 0:
            result += generate_parentheses(open_count, close_count - 1)
        
        memo[(open_count, close_count)] = result
        return result
    
    return generate_parentheses(n, n)

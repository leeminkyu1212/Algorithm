def solution(ingredient):
    stack = []
    count = 0
    
    for item in ingredient:
        stack.append(item)
        if stack[-4:] == [1, 2, 3, 1]:
            count += 1
            for _ in range(4):
                stack.pop()
    
    return count

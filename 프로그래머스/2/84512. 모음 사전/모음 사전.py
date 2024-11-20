import sys
sys.setrecursionlimit(100000)

def solution(word):
    alpha = 'AEIOU'
    answer = 0
    level=0
    def dfs(string):
        nonlocal answer,level
        if string == word:
            answer = level
            return
        
        if len(string) >= 5:
            return
        
        for i in range(5):
            string += alpha[i]
            level+=1
            dfs(string)
            string = string[:-1]
    
    dfs('')
    return answer

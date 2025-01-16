# ProjectRoot/src/solution.py
import re
from itertools import permutations

def solution(expression):
    tokens = re.split(r'([+\-*])', expression)
    tokens = [t for t in tokens if t]

    operators = set()
    for t in tokens:
        if t in ['+', '-', '*']:
            operators.add(t)

    max_value = 0
    for ops in permutations(operators, len(operators)):
        tmp = tokens[:]
        for op in ops:
            stack = []
            i = 0
            while i < len(tmp):
                if tmp[i] == op:
                    prev_num = stack.pop()
                    next_num = tmp[i+1]
                    if op == '+':
                        stack.append(str(int(prev_num) + int(next_num)))
                    elif op == '-':
                        stack.append(str(int(prev_num) - int(next_num)))
                    else:
                        stack.append(str(int(prev_num) * int(next_num)))
                    i += 2
                else:
                    stack.append(tmp[i])
                    i += 1
            tmp = stack
        max_value = max(max_value, abs(int(tmp[0])))

    return max_value

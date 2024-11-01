def make_base_number(number_str: str, base: int) -> int:
    """주어진 진법으로 숫자 문자열을 정수로 변환"""
    number = 0
    for idx, digit in enumerate(number_str[::-1]):
        number += int(digit) * (base ** idx)
    return number

def plus_or_minus(first: int, second: int, op: str) -> int:
    """덧셈 혹은 뺄셈 연산을 수행"""
    if op == '+':
        return first + second
    elif op == '-':
        return first - second

def find_base(expression: list, bases: set) -> set:
    """알려진 수식을 통해 가능한 진법을 찾음"""
    new_base = set()
    for base in bases:
        try:
            first = make_base_number(expression[0], base)
            second = make_base_number(expression[2], base)
            result = make_base_number(expression[4], base)
            if plus_or_minus(first, second, expression[1]) == result:
                new_base.add(base)
        except ValueError:
            continue
    return new_base

def return_number(number: int, base: int) -> str:
    """정수를 주어진 진법으로 변환하여 문자열로 반환"""
    if number == 0:
        return "0"
    
    base_number = ""
    while number > 0:
        remainder = number % base
        base_number = str(remainder) + base_number
        number //= base
    
    return base_number

def solution(expressions):
    known_expressions = []
    unknown_expressions = []
    max_num = 0

    for expression in expressions:
        parts = expression.split()
        if parts[4] == "X":
            unknown_expressions.append(parts)
        else:
            known_expressions.append(parts)
        
        for digit in expression.replace(" ", ""):
            if digit.isdigit():
                max_num = max(max_num, int(digit))

    bases = {2, 3, 4, 5, 6, 7, 8, 9}
    bases = {base for base in bases if base > max_num}

    # 알려진 수식을 통해 가능한 진법을 추론
    for expression in known_expressions:
        bases &= find_base(expression, bases)

    answer = []
    for expression in unknown_expressions:
        possible_results = set()
        for base in bases:
            try:
                first = make_base_number(expression[0], base)
                second = make_base_number(expression[2], base)
                result = plus_or_minus(first, second, expression[1])
                result_str = return_number(result, base)
                possible_results.add(result_str)
            except ValueError:
                continue

        if len(possible_results) == 1:
            expression[4] = possible_results.pop()
        elif len(possible_results) > 1:
            if len(set(possible_results)) == 1:
                expression[4] = possible_results.pop()
            else:
                expression[4] = "?"
        else:
            expression[4] = "?"
        
        answer.append(" ".join(expression))

    return answer

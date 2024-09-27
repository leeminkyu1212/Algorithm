new_dict = {0: 0, 1: 1, 2: 1}


def fibo(n: int) -> int:
    if n not in new_dict:
        new_dict[n] = fibo(n - 1) + fibo(n - 2)

    return new_dict[n]


n = int(input())
print(fibo(n))

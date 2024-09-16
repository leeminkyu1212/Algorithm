dict_fibo = {
    0: 0,
    1: 1,
}

def fibo(x: int) -> int:
    if x in dict_fibo:
        return dict_fibo[x]
    else:
        dict_fibo[x] = fibo(x-1) + fibo(x-2)
        return dict_fibo[x]

N = int(input())
print(fibo(N))

prime_list = []

def prime(i: int):
    global prime_list
    if i < 2:
        return
    for j in range(2, int(i ** 0.5) + 1):
        if i % j == 0:
            return
    prime_list.append(i)

M = int(input())
N = int(input())

for i in range(M, N + 1):
    prime(i)

if len(prime_list) == 0:
    print(-1)
else:
    print(sum(prime_list))
    print(prime_list[0])

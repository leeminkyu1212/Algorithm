n = int(input())

for _ in range(n):
    p = int(input())
    max = 0
    name = ""
    for _ in range(p):
        price, player = input().split()
        price = int(price)
        if price > max:
            name = player
            max = price
    print(name)
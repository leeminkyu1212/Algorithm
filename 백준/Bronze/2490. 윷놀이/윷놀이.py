for i in range(3):
    sum1 = sum(list(map(int, input().split())))
    if sum1 == 4:
        print("E")
    elif sum1 == 3:
        print("A")
    elif sum1 == 2:
        print("B")
    elif sum1 == 1:
        print("C")
    else:
        print("D")

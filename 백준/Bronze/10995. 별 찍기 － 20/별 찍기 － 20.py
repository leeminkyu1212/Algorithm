def print_star_pattern(n):
    for i in range(n):
        if i % 2 == 0:
            print('* ' * n)
        else:
            print(' *' * n)

n = int(input())

print_star_pattern(n)

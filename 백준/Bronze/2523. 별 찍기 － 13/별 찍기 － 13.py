def print_star_pattern(n):
    for i in range(1, n + 1):
        stars = '*' * i
        print(stars)

    for i in range(n - 1, 0, -1):
        stars = '*' * i
        print(stars)

n = int(input())

print_star_pattern(n)

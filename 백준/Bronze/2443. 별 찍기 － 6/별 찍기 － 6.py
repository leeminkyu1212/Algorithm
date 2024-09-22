def print_star_pattern(n: int):
    for i in range(n):
        spaces = ' ' * i
        stars = '*' * (2 * (n - i) - 1)
        print(spaces + stars)

n = int(input())

print_star_pattern(n)

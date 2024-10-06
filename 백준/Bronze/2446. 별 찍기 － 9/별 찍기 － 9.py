def print_star_pattern(n):
    for i in range(n):
        print(' ' * i + '*' * (2 * (n - i) - 1))
    for i in range(n - 2, -1, -1):
        print(' ' * i + '*' * (2 * (n - i) - 1))

if __name__ == "__main__":
    n = int(input())
    print_star_pattern(n)

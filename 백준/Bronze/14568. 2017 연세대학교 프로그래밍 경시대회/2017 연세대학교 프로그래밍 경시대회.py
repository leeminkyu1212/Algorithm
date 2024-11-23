N = int(input())

count = 0

for A in range(2, N + 1, 2):
    for B in range(1, N + 1):
        C = N - A - B
        if C <= 0:
            continue
        if C >= B + 2:
            count += 1

print(count)

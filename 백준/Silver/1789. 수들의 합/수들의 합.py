S = int(input())

N = 0
sum_of_numbers = 0

while sum_of_numbers <= S:
    N += 1
    sum_of_numbers += N

print(N - 1)

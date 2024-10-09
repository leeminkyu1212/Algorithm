numbers = list(map(int, input().split()))

total_sum = sum(num ** 2 for num in numbers)

verification_number = total_sum % 10

print(verification_number)

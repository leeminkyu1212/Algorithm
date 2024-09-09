operations = {
  '*': lambda x, y: x * y,
  '+': lambda x, y: x + y
}

A = int(input())
operation = input()
B = int(input())

print(f"{operations[operation](A, B)}")

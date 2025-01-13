N = int(input())
M = int(input())
S = input()

total = 0
i = 0
while i < M:
    if S[i] == 'I':
        countIO = 0
        while i + 2 < M and S[i + 1] == 'O' and S[i + 2] == 'I':
            countIO += 1
            i += 2
        if countIO >= N:
            total += (countIO - N + 1)
        i += 1
    else:
        i += 1

print(total)

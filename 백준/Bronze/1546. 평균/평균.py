N = int(input())


score = list(map(int, input().split()))
score.sort()
M = score[N - 1]
new_score = [x / M * 100 for x in score]
print(f"{sum(new_score)/N:.3f}")

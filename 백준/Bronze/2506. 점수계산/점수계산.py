N = int(input())

new_list = list(map(int, input().split()))

count_list=[]
count_list.append(new_list[0])

for i in range(1, N):
  if new_list[i] == 1:
    count_list.append(count_list[i - 1] + 1)
  else :
    count_list.append(0)


print(sum(count_list))
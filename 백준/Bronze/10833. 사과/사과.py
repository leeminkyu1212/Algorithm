def remain(student, apple):
  quote = apple // student
  if quote != 0:
    return apple - student * quote
  return apple


N = int(input())

new_list = []
for _ in range(N):
  student, apple = map(int, input().split())
  new_list.append(remain(student, apple))


print(sum(new_list))

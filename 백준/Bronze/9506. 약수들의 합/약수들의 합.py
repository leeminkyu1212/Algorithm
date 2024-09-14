def perfect_number(n: int):
  div_list = [x for x in range(1, int(n / 2) + 1) if n % x == 0]
  if sum(div_list) == n:
    div_list = list(map(str, div_list))
    div_list_all = ' + '.join(div_list)
    print(f"{n} = {div_list_all}")
    return
  else:
    print(f"{n} is NOT perfect.")


while True:
  n = int(input())
  if (n == -1):
    break
  else:
    perfect_number(n)

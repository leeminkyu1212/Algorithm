abc = {300: 0, 60: 0, 10: 0}


def microwave(remain: int):
  global abc

  if remain == 0:
    print(f"{abc[300]} {abc[60]} {abc[10]}")
    return
  elif remain < 10:
    print(-1)
    return
  else:
    for time in abc:
      if (remain < time):
        pass
      else:
        remain = remain - time
        abc[time] += 1
        microwave(remain)
        return


T = int(input())

microwave(T)

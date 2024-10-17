def method():
  idx = 0
  count = 0
  global pdg,A,T
  for i in range(2, 1000):
    str = '0101' + i * '0' + i * '1'
    for c in str:
      if c == pdg:
        count += 1
        if count == T:
          print(idx % A)
          return
      idx += 1


A = int(input())
T = int(input())
pdg = input()

method()

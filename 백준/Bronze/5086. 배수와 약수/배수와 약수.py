while True:
  A, B = map(int, input().split())
  if A == B == 0: break;
  if B % A == 0 and A < B:
    print("factor")
  elif A % B == 0 and B < A:
    print("multiple")
  else:
    print("neither")

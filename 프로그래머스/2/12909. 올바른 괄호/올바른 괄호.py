def solution(s):
  from collections import deque
  q = deque()
  for char in s:
    q.append(char)
  count = 0
  while q:

    if q[0] == '(':
        q.popleft()
        count += 1
    elif q[0] == ')':
        if count == 0:
            return False
        else:
            q.popleft()
            count -= 1

  if count > 0:
    return False

  return True
def solution(progresses, speeds):
  from collections import deque
  answer = []

  prog_q = deque(progresses)
  speed_q = deque(speeds)
  while prog_q:
    count = 0
    while prog_q and prog_q[0] >= 100 :
      prog_q.popleft()
      speed_q.popleft()
      count += 1
    if count != 0:
      answer.append(count)
    for i in range(len(prog_q)):
      prog_q[i] += speed_q[i]

  return answer



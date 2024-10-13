cur = 0
_max = -1
for i in range(4):
  _out, _in = map(int, input().split())
  cur += _in - _out
  _max = max(cur, _max)

print(_max)

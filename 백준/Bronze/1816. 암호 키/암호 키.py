import math


def generate_primes(limit):
  is_prime = [True] * (limit + 1)
  is_prime[0] = is_prime[1] = False
  for i in range(2, int(math.sqrt(limit)) + 1):
    if is_prime[i]:
      for j in range(i * i, limit + 1, i):
        is_prime[j] = False
  return [x for x in range(limit + 1) if is_prime[x]]


def is_valid_key(s, primes):
  for prime in primes:
    if prime * prime > s:
      break
    if s % prime == 0:
      return False
  return True

n = int(input())
numbers = [int(input()) for _ in range(n)]

primes = generate_primes(10 ** 6)

results = []
for s in numbers:
  if is_valid_key(s, primes):
    results.append("YES")
  else:
    results.append("NO")

print("\n".join(results))

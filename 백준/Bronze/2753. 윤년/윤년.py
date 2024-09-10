
def moon_year(year:int):
  if not year % 4 and(year%100 or not year %400):
    return 1
  return 0


year=int(input())
print(moon_year(year))
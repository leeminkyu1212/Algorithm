students = {
  "wonsop": 0,
  "saehee": 0,
  "sangun": 0,
  "seung": 0,
  "kangsu": 0,
}

for student in students:
  students[student]=int(input())
  if students[student] < 40: students[student] = 40;
avg_score = sum(students.values()) / len(students)

print(f"{avg_score:.0f}")

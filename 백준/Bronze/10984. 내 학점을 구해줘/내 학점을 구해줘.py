T = int(input())

for _ in range(T):
    N = int(input())
    semester = []
    for __ in range(N):
        C, G = map(float, input().split())
        semester.append([C, G])
    C_sum=sum(x[0] for x in semester)
    GPA=sum(x[0]*x[1]/C_sum for x in semester)
    print(f"{C_sum:.0f} {GPA:.1f}")
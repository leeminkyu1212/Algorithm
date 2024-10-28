def calculate_orders(N, shirt_sizes, T, P):
    total_shirt_bundles = 0
    for count in shirt_sizes:
        total_shirt_bundles += (count + T - 1) // T
    pen_bundles = N // P
    remaining_pens = N % P

    return total_shirt_bundles, pen_bundles, remaining_pens


N=int(input())
shirt_sizes = list(map(int,input().split()))
T,P=map(int,input().split())
total_shirt_bundles, pen_bundles, remaining_pens = calculate_orders(N, shirt_sizes, T, P)

print(total_shirt_bundles)
print(pen_bundles, remaining_pens)

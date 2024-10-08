
N,X=map(int,input().split())

input_list=map(int,input().split())
new_list=[str(x) for x in input_list if x<X]

result=' '.join(new_list)
print(result)

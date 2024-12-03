

a,b=map(int,input().split())
new_list=[]
for i in range(1,b+1):
  temp_list=[i for _ in range(i)]
  new_list+=temp_list

print(sum(new_list[a-1:b]))

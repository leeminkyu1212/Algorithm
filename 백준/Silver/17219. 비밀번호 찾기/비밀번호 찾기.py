N,M=map(int,input().split())

pw_dict={}

for _ in range(N):
  site,pw=input().split()
  pw_dict[site]=pw

for _ in range(M):
  site=input()
  print(pw_dict[site])
a,b,c,d,e,f=map(int,input().split())

def calc(a,b,c,d,e,f):
  x=(b*f-c*e)//(b*d-a*e)
  y=(a*f-c*d)//(a*e-b*d)
  return x,y

x,y=calc(a,b,c,d,e,f)
print(x,y)


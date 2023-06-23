import math
M=int(input())
N=int(input())
a=[]
for i in range(int(math.sqrt(M)), int(math.sqrt(N))+1):
    if i*i>=M and i*i <= N:
        a.append(i*i)
if len(a)==0:
    print(-1)
else:   
    print(sum(a))
    print(a[0])

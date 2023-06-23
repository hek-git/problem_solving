a=int(input())
n=2*a-1
s=0
for i in range(n):
    print(" "*s, end='')
    print("*"*(n-s*2))
    s+=1
    if i>int(n/2-1):
        s-=2

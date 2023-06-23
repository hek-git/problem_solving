n=int(input())
A,B,C=0,0,0
ans=0
for A in range(1,n):
    for B in range(1,n):
        for C in range(1,n):
            if A%2==0 and B<=C-2 and (A+B+C)==n:
                ans+=1
print(ans)
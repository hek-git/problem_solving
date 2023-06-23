N,M,K = map(int, input().split())
ans=0
for i in range(K+1):
    n=N-i
    m=M-(K-i)
    a=0
    while n>1 and m>0:
        n-=2
        m-=1
        a+=1
    ans = max(ans, a)
print(ans)
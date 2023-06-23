a, b, n, w = map(int, input().split())
answer=0
s, g=0,0
for i in range(1,n):
    if (a*i+b*(n-i))==w:
        answer += 1
        s=i
        g=n-i
if answer>1 or answer == 0:
    print(-1)
else:
    print(s,g)
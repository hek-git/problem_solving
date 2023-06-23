ans=[]
for i in range(9):
    ans.append(int(input()))
ans.sort()
for i in range(len(ans)):
    for j in range(i+1,len(ans)):
        if (sum(ans)-ans[i]-ans[j])==100:
            a, b = ans[i], ans[j]
            break
ans.remove(a)
ans.remove(b)
print(*ans, sep='\n')
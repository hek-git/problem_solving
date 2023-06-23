a=[]
b=[]
c=0
for i in range(10):
    a.append(int(input()))
if a[0]==100:
    print(100)
    exit(0)
for i in a:
    c+=i
    b.append(c)
for i, j in enumerate(b):
    if j>=100:
        c = b[i-1] if abs(100-b[i-1]) < abs(100-j) else j
        break
print(c)
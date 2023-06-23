# x^2 + 2Ax + B = 0
import math
A, B = map(int, input().split())
a=int((-2*A-int(math.sqrt((2*A)**2-4*B)))/2)
b=int((-2*A+int(math.sqrt((2*A)**2-4*B)))/2)
if a==b:
    print(a)
else:
    print(a,b)
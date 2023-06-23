# import math
# n=int(input())
# for i in range(n):
#     N,M=map(int, input().split(" "))
#     print(int(math.factorial(M)/(math.factorial(M-N)*math.factorial(N))))

import math
n=int(input())
for i in range(n):
    N,M=map(int, input().split(" "))
    for j in range(M):
        for k in range(j):
            if (int(math.factorial(j)/math.factorial(j-k)/math.factorial(k)) is not int(math.factorial(j)/(math.factorial(j-k)*math.factorial(k)))):    
            # print(int(math.factorial(j)/math.factorial(j-k)/math.factorial(k)), j)
            #print(int(math.factorial(j)/(math.factorial(j-k)*math.factorial(k))), k)
                print(j)
                print(k)
                print()
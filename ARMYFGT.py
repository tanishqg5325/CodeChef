import math

def gcd(m,n):
    if(n == 0):
        return m
    return gcd(n,m%n)

def lcm(m,n):
    return m*n//gcd(m,n)

t = int(input())
for _ in range(t):
    n = int(input())
    ar = list(map(int, input().split(" ")))
    low, high = map(int, input().split(" "))
    least = ar[0]
    flag = 1
    for i in range(1,n):
        least = lcm(least, ar[i])
        if(least > 10**18):
            flag = 0
            break
    if flag == 0:
        print(high-low+1)
    else:
        ans = high - low + 1
        if (low % least == 0):
            print(ans - (high//least) + (low//least) - 1)
        else:
            print(ans - (high//least) + (low//least))

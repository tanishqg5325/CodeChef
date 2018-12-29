prime = [1] * 501
for i in range(2,501):
    if prime[i] == 1:
        for j in range(i*i,501,i):
            prime[j] = 0

primes = []
for i in range(2,501):
    if prime[i] == 1:
        primes.append(i)

for _ in range(20):
    n = int(input())
    ans = 1
    i = 0
    while (ans * primes[i]) <= n:
        ans = ans * primes[i]
        i += 1
    print(ans)

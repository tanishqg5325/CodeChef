#include <bits/stdc++.h>
#define pb push_back
#define MAX_N 100000001
using namespace std;

int prime[MAX_N / 64];
vector<int> primes;

bool ifnotPrime(int x)
{
    return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

bool makeComposite(int x)
{
    prime[x/64] |= (1 << ((x >> 1) & 31));
}

void bitWiseSieve()
{
    for(int i = 3; i * i < MAX_N; i += 2)
        if(!ifnotPrime(i))
            for (int j = i * i, k = i << 1; j < MAX_N; j += k)
                makeComposite(j);
    primes.pb(2);
    for(int i = 3; i < MAX_N; i += 2)
        if(!ifnotPrime(i))
            primes.pb(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bitWiseSieve();
    int n = primes.size();
    for(int i=0;i<n;i+=100) cout<<primes[i]<<"\n";
	return 0;
}

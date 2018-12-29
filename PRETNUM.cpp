#include <bits/stdc++.h>
typedef long long ll;
#define MAX_N 1000001
using namespace std;

bool isPrime[MAX_N];

void sieve()
{
    for (int i=2;i < MAX_N;i++) isPrime[i] = 1;
    for (int i=2;i*i < MAX_N;i++)
        if (isPrime[i])
            for (int j=i*i;j < MAX_N;j+=i)
                isPrime[j] = false;
}

int ans(ll l , ll r)
{
    int divisors[r-l+1]{};
    for(ll i=1;i*i<=r;i++)
    {
        for(ll j=ceil(1.0*l/i)*i;j<=r;j+=i)
        {
            if(i*i > j) continue;
            if(i*i == j) divisors[j-l]++;
            else divisors[j-l] += 2;
        }
    }
    int count = 0;
    for(int i=0;i<=r-l;i++)
        if(isPrime[divisors[i]])
            count++;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve();
    int t; ll l,r; cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<ans(l,r)<<"\n";
    }
    return 0;
}

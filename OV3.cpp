#include <bits/stdc++.h>
typedef long long ll;
#define MAX_N 100001
using namespace std;

ll mod = 1000000007;

ll mod_inv(ll x, ll y)
{
    if (y == 0) return 1;
    ll p = mod_inv(x,y/2)%mod;
    p = (p*p)%mod;
    return (y%2 == 0)?p:(x*p)%mod;
}

ll mod_inv(ll x)
{
    return mod_inv(x, mod-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll fact[MAX_N];
    fact[0] = 1;
    for(int i=1;i<MAX_N;i++) fact[i] = (fact[i-1] * i) % mod;
    int n; cin>>n;
    ll ans = fact[n];
    int ar[n-1];
    for(int i=0;i<n-1;i++) {cin>>ar[i]; ans = (ans * mod_inv(fact[ar[i]])) % mod;}
    if(n == 1) {cout<<"1\n"; return 0;}
    ans = (ans * fact[n-2]) % mod;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<ar[i];j++)
            ans = (ans * mod_inv(fact[i])) % mod;
    }
    cout<<ans<<"\n";
	return 0;
}

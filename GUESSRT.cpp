#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll power(ll n, ll p)
{
	int ans = 1;
    while (p)
	{
        if (p & 1) ans = (ans * n) % mod;
        p = p >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; ll n,k,m,p,q,ans; cin>>T;
    while(T--)
    {
        cin>>n>>k>>m;
        p = power(n-1, ceil(m/2.0));
        q = power(n, ceil(m/2.0));
        if(m % 2 == 0)
        {
            p = (p * (n+k-1)) % mod;
            q = (q * (n+k)) % mod;
        }
        p = (q - p + mod) % mod;
        ans = p * power(q, mod-2) % mod;
        cout<<ans<<"\n";
    }
    return 0;
}

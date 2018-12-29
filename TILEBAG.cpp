#include <bits/stdc++.h>
#define pll pair<ll,ll>
typedef long long ll;
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
    int t; ll x,y,s,u,v;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>s>>u>>v;
        ll ans = 1;
        while(s != x && s != y)
        {
            s /= 2;
            ans *= 2;
        }
        if(s == x)
        {
            ans %= mod;
            ans = (ans*v) % mod;
            ans = (ans*mod_inv(u)) % mod;
        }
        else
        {
            ll tm = v-u;
            ans %= mod;
            ans = (ans*v) % mod;
            ans = (ans*mod_inv(tm)) % mod;
        }
        cout<<ans<<"\n";
    }
	return 0;
}

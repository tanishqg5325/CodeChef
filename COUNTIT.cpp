#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll power(ll n, int p)
{
	ll ans = 1;
    while(p)
	{
        if(p & 1) ans = (ans * n) % mod;
        p = p >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,k; ll ans,t1,t2; cin>>T;
    while(T--)
    {
        cin>>n>>m>>k; ans = 0;
        ll y[n+m+1]; y[0] = 0;
        for(int i=1;i<=n+m;i++)
        {
            ll tmp1 = (power(i, n) + mod - power(i-1, n)) % mod;
            ll tmp2 = (power(i, m) + mod - power(i-1, m)) % mod;
            y[i] = (y[i-1] + tmp1 * tmp2) % mod;
        }
        if(k <= n+m) {cout<<y[k]<<"\n"; continue;}
        ll num = 1; for(int i=1;i<=n+m;i++) num = (num * (k - i)) % mod;
        ll fact[n+m]; fact[0] = 1; for(int i=1;i<n+m;i++) fact[i] = (fact[i-1] * i) % mod;
        for(int i=1;i<=n+m;i++)
        {
            ll tmp = (y[i] * power(((fact[n+m-i] * fact[i-1]) % mod * (k-i)) % mod, mod-2)) % mod;
            ans = (ans + power(-1, n+m-i) * tmp + mod) % mod;
        }
        cout<<(ans * num) % mod<<"\n";
    }
    return 0;
}

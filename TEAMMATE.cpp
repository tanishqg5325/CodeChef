#include <bits/stdc++.h>
#define pb push_back
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

ll power(int x, ll n)
{
    if(n == 0) return 1;
    ll tmp = power(x, n/2);
    tmp = (tmp * tmp) % mod;
    if(n % 2) tmp = (tmp * x) % mod;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k;
    ll fact[100001]; fact[0]=fact[1]=1;
    for(int i=2;i<=100000;i++) fact[i] = (fact[i-1]*i) % mod;
    cin>>t;
    while(t--)
    {
        cin>>n; int s[n];
        for(int i=0;i<n;i++) cin>>s[i];
        sort(s,s+n,greater<int>());
        vector<pair<int,int>> v;
        pair<int,int> p; p.first = s[0]; p.second = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1]) p.second++;
            else { v.pb(p); p.first = s[i]; p.second = 1; }
        }
        v.pb(p);
        k = v.size(); ll ans = 1;
        for(int i=0;i<k;i++)
        {
            int m = v[i].second;
            if(m % 2)
            {
                ans = (ans * m * v[i+1].second) % mod;
                v[i+1].second--; m--;
            }
            ans = (ans * fact[m])% mod;
            ans = (ans * mod_inv(fact[m/2])) % mod;
            ans = (ans * mod_inv(power(2,m/2))) % mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

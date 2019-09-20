#include <bits/stdc++.h>
#define X first
#define Y second
#define N 200001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll mod = 1000000007;
pll aux[N]; ll fact[N], inv_fact[N];

ll power(ll n, ll p)
{
	ll ans = 1;
    while(p)
	{
        if(p & 1) ans = (ans * n) % mod;
        p = p >> 1; n = (n * n) % mod;
    }
    return ans;
}

void fillu()
{
    for(int i=1;i<N;i++) aux[i] = {1, i};
    for(int i=2;i<N;i++)
    {
        aux[i].Y--;
        for(int j=2;j*j<=i;j++)
            if(i % j == 0)
            {
                aux[i].Y -= aux[j].Y;
                int l = i/j;
                if(l != j) aux[i].Y -= aux[l].Y;
            }
    }
    fact[0] = 1; for(int i=1;i<N;i++) fact[i] = (fact[i-1] * i) % mod;
    for(int i=0;i<N;i++) inv_fact[i] = power(fact[i], mod-2);
}

ll ncr(int n, int k)
{
    if(k > n) return 0;
    ll ans = (inv_fact[k] * inv_fact[n-k]) % mod;
    ans = (fact[n] * ans) % mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q,k,n,l; fillu(); cin>>q>>k;
    ll ans[N], curr = 0; ans[1] = 0;
    for(int i=2;i<N;i++)
    {
        curr = (curr + ncr(aux[1].X++, k-1)) % mod;
        for(int j=2;j*j<=i;j++)
            if(i % j == 0)
            {
                curr = (curr + aux[j].Y * ncr(aux[j].X++, k-1)) % mod;
                l = i/j;
                if(l != j)
                    curr = (curr + aux[l].Y * ncr(aux[l].X++, k-1)) % mod;
            }
        if(i < k) ans[i] = 0;
        else ans[i] = (curr * power(ncr(i, k), mod-2)) % mod;
    }
    while(q--)
    {
        cin>>n;
        cout<<ans[n]<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define MAXN 10000001
typedef long long ll;
using namespace std;

ll mod = 1000000007;
int spf[10000001];

ll power(ll n, ll p)
{
	int ans = 1;
    while(p)
	{
        if(p & 1) ans = (ans * n) % mod;
        p = p >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

void sieve()
{
    spf[1] = 1;
    for(int i=2;i<MAXN;i++) spf[i] = i;
    for(int i=4;i<MAXN;i+=2) spf[i] = 2;
    for(int i=3;i*i<MAXN;i++)
        if(spf[i] == i)
            for (int j=i*i;j<MAXN;j+=i) if(spf[j]==j) spf[j] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m,p,q,temp,ans=0,count; cin>>n>>m>>p>>q;
	ll f[q+1], poly[n+1]{}, pow_p[n+1], weight[n+1], prefix[n+1], pow_m[26];
	for(int i=0;i<=q;i++) cin>>f[i];
	for(int d=1;d<=n;d++)
	{
		temp = 1;
		for(int j=0;j<=q;j++)
		{
			poly[d] = (poly[d] + (temp * f[q-j]) % mod) % mod;
			temp = (temp * d) % mod;
		}
	}

	for(int i=1;i<=n;i++) pow_p[i] = power(i,p);

	pow_m[0] = 0;
	for(int i=1;i<=25;i++) pow_m[i] = power(i,m);

	weight[1] = 1; sieve(); vector<int> v;
	for(int i=2;i<=n;i++)
	{
	    int x = i; v.clear();
		while (x != 1)
        {
            temp = spf[x]; count = 0;
            while(!(x%temp)) {count++; x /= temp;}
            v.pb(count);
        }
		weight[i] = 1;
		int r = v.size();
		for(int j=0;j<r;j++)
			weight[i] = (weight[i] * ((pow_m[v[j]+1] - 2*pow_m[v[j]] + pow_m[v[j]-1] + mod*2) % mod)) % mod;
	}

	prefix[1] = weight[1];
	for(int i=2;i<=n;i++) prefix[i] = (prefix[i-1] + ((pow_p[i] * weight[i]) % mod)) % mod;
	for(int i=1;i<=n;i++)
		ans = (ans + ((((poly[i] * pow_p[i]) % mod) * prefix[n/i]) % mod)) % mod;
	cout<<ans<<"\n";
    return 0;
}

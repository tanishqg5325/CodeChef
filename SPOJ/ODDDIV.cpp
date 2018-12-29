#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100001
typedef long long ll;
using namespace std;

int spf[MAXN];
vector<ll> sq[10001];

void sieve()
{
    spf[1] = 1;
    for(int i=2;i<MAXN;i++) spf[i] = i;
    for(int i=4;i<MAXN;i+=2) spf[i] = 2;
    for(int i=3;i*i<MAXN;i++)
        if(spf[i] == i)
            for (int j=i*i;j<MAXN;j+=i) if(spf[j]==j) spf[j] = i;
    ll one = 1; int x,fact,temp,count;
    for(int i=1;i<MAXN;i++)
    {
        x = i, fact=1;
		while (x != 1)
        {
            temp = spf[x]; count = 0;
            while(!(x%temp)) {count++; x /= temp;}
            fact = fact * (1 + 2*count);
        }
        if(fact < 10001) sq[fact].pb(one*i*i);
    }
}

ll ans(int k, ll l, ll r)
{
    return upper_bound(sq[k].begin(), sq[k].end(), r) - lower_bound(sq[k].begin(), sq[k].end(), l);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve();
    int t,k; ll l,r;
    cin>>t;
    while(t--)
    {
        cin>>k>>l>>r;
        cout<<ans(k,l,r)<<"\n";
    }
	return 0;
}

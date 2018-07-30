#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
using namespace std;

ll mod = 1000000009;

int bsearch(pair<ll,int> p[], int n, ll k)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(p[mid].first == k) return mid;
        else if(p[mid].first > k) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

ll mod_inv(ll x, ll y)
{
    if (y == 0) return 1;
    ll p = mod_inv(x,y/2)%mod;
    p = (p*p)%mod;
    return (y%2 == 0)?p:(x*p)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    ll a,b,ans[n];
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        ans[i] = 4*a*b + 2*max(a,b);
    }
    sort(ans,ans+n);
    pair <ll,int> pairs[n]; int p=0,count;
    for(int i=0;i<n;i++)
    {
        count=1;
        while(i+1<n && ans[i]==ans[i+1])
        {
            i++; count++;
        }
        pairs[p].first=ans[i]; pairs[p].second=count;
        p++;
    }
    ll k[q];
    for(int i=0;i<q;i++) {cin>>k[i]; k[i]=k[i]*(k[i]+1); }
    for(int i=0;i<q;i++)
    {
        int tmp = bsearch(pairs,p,k[i]);
        if(tmp==-1) {cout<<"-1\n"; continue;}
        cout<<mod_inv(pairs[tmp].second, mod-2)<<"\n";
    }
    return 0;
}

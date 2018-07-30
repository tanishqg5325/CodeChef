#include <bits/stdc++.h>
#include <cmath>
#include <limits>
typedef long long ll;
using namespace std;

ll num = 1000000000;

void buildtree(ll low, ll high, ll pos, ll a[], ll tree[])
{
    if (low == high)
    {
        tree[pos] = a[low];
        return;
    }
    int mid = (low + high) >> 1;
    buildtree(low, mid, 2 * pos + 1, a, tree);
    buildtree(mid + 1, high, 2 * pos + 2, a, tree);
    if (tree[2 * pos + 1] < tree[2 * pos + 2])
        tree[pos] = tree[2 * pos + 1];
    else if (tree[2 * pos + 1] > tree[2 * pos + 2])
        tree[pos] = tree[2 * pos + 2];
    else
        tree[pos] = tree[2 * pos + 1];
}

pair<ll,ll> query(ll node, ll start, ll end, ll l, ll r, ll k, ll ar[])
{
    if (start>r || end<l)
        return make_pair(numeric_limits<ll>::max(), numeric_limits<ll>::max());

    if(l<=start && end <= r)
        return make_pair((ll)abs(num - ar[node] - k), ar[node]);

    ll mid = (start + end) / 2;
    pair<ll,ll> p1 = query(2*node+1, start, mid, l, r, k, ar);
    pair<ll,ll> p2 = query(2*node+2, mid+1, end, l, r, k, ar);
    if(p1.first<p2.first) return p1;
    if(p1.first>p2.first) return p2;
    return make_pair(p1.first, min(p1.second, p2.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,l,r,k;
    cin>>n>>q;
    ll ar[n];
    for(ll i=0;i<n;i++) cin>>ar[i];
    ll tree[200000]{};
    buildtree(0,n-1,0,ar,tree);
    while(q--)
    {
        cin>>l>>r>>k;
        pair<ll,ll> p = query(0,0,n-1,l-1,r-1,k,tree);
        cout<<p.second<<"\n";
    }
    return 0;
}

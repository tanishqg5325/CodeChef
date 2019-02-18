#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
typedef long long ll;

int n;

ll find_cf(int idx, ll tree[])
{
    ll sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, ll tree[])
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n; int ar[n]; ll tree1[n+1]{}, tree2[n+1]{}; ll ans = 0;
    for(int i=0;i<n;i++) cin>>ar[i];
    for(int i=n-1;i>=0;i--)
    {
        ans = ans + find_cf(ar[i]-1, tree2);
        update(ar[i], find_cf(ar[i]-1, tree1), tree2);
        update(ar[i], 1, tree1);
    }
    cout<<ans<<"\n";
    return 0;
}

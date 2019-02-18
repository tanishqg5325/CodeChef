#include <bits/stdc++.h>
#define MAXN 10000001
using namespace std;
typedef long long ll;

int tree[MAXN];

int find_cf(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while (idx < MAXN)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,a; cin>>T;
    while(T--)
    {
        cin>>n; ll ans = 0;
        memset(tree, 0, sizeof(tree));
        for(int i=0;i<n;i++)
        {
            cin>>a;
            ans = ans + find_cf(MAXN-1) - find_cf(a);
            update(a, 1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

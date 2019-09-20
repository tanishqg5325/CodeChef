#include <bits/stdc++.h>
#define inf 100001
using namespace std;

struct play
{
    int a,b,c;
    bool operator < (const play &p) const
    {
        return a < p.a;
    }
};

int read(int idx, int tree[])
{
    int ans = inf;
    while(idx > 0)
    {
        ans = min(ans, tree[idx]);
        idx -= (idx & -idx);
    }
    return ans;
}

void update(int idx, int val, int tree[], int MaxIdx)
{
    while(idx <= MaxIdx)
    {
        tree[idx] = min(tree[idx], val);
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; cin>>T;
    while(T--)
    {
        cin>>n; play pl[n];
        for(int i=0;i<n;i++) cin>>pl[i].a>>pl[i].b>>pl[i].c;
        sort(pl, pl+n);
        int bit[n+1];
        for(int i=0;i<=n;i++) bit[i] = inf;
        update(pl[0].b, pl[0].c, bit, n);
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            if(read(pl[i].b - 1, bit) > pl[i].c) ans++;
            update(pl[i].b, pl[i].c, bit, n);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

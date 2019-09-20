#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct Coder
{
    int X, Y, idx;
    bool operator < (const Coder &q) const
    {
        return X <= q.X;
    }
};

struct Query
{
    int l, r, idx1, idx2;
    bool operator < (const Query &q) const
    {
        return r <= q.r;
    }
};

int find_cf(int idx, int tree[])
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int tree[], int MaxIdx)
{
    while(idx <= MaxIdx)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, idx = 1, t; cin>>n; Coder coder[n+1]; Query query[n+1]; int ans[n+1], bit[n+1]{};
    unordered_map<int, unordered_map<int, int>> freq;
    for(int i=1;i<=n;i++) {cin>>coder[i].X>>coder[i].Y; coder[i].idx = i; freq[coder[i].X][coder[i].Y]++;}
    sort(coder+1, coder+n+1);
    for(int i=1;i<=n;i++) query[i] = {coder[i].X, coder[i].Y, coder[i].idx, i};
    sort(query+1, query+n+1);
    vector<int> left; for(int i=1;i<=n;i++) left.pb(coder[i].X);
    while(idx <= n)
    {
        int j = idx;
        while(idx <= n && query[j].r == query[idx].r) {update(query[idx].idx2, 1, bit, n); idx++;}
        for(int k=j;k<idx;k++)
        {
            t = upper_bound(left.begin(), left.end(), query[k].l) - left.begin();
            ans[query[k].idx1] = find_cf(t, bit) - freq[query[k].l][query[k].r];
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}

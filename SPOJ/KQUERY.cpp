#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

struct Query
{
    int l, r, k, idx;
};

bool cmp(Query &x, Query &y)
{
    return x.k > y.k;
}

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

void answeringQueries(pii arr[], int n, Query queries[], int q)
{
    int bit[n+1]{}, ans[q], query_counter = 0;
    int k = 0;
    for (int i=0;i<q;i++)
    {
        while(arr[k].F > queries[i].k) {update(arr[k].S + 1, 1, bit, n); k++;}
        ans[queries[i].idx] = find_cf(queries[i].r + 1, bit) - find_cf(queries[i].l, bit);
    }
    for (int i=0; i<q; i++) cout<<ans[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q; cin>>n; pii ar[n];
    for(int i=0;i<n;i++) {cin>>ar[i].F; ar[i].S = i;}
    cin>>q;
    Query queries[q];
    for(int i=0;i<q;i++)
    {
        cin>>queries[i].l>>queries[i].r>>queries[i].k;
        queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }
    sort(queries, queries+q, cmp);
    sort(ar, ar+n, greater<pii>());
    answeringQueries(ar, n, queries, q);
    return 0;
}

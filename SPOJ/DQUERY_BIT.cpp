#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

struct Query
{
    int l, r, idx; // 0 <= l,r < n
};

bool cmp(Query &x, Query &y)
{
    return x.r < y.r;
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

void answeringQueries(int arr[], int n, Query queries[], int q)
{
    int bit[n+1]{}, last_visit[MAX], ans[q], query_counter = 0;
    for(int i=0;i<MAX;i++) last_visit[i] = -1;
    for (int i=0;i<n;i++)
    {
        if(last_visit[arr[i]] != -1) update(last_visit[arr[i]] + 1, -1, bit, n);
        last_visit[arr[i]] = i;
        update(i + 1, 1, bit, n);
        while(query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] =
                     find_cf(queries[query_counter].r + 1, bit)-
                     find_cf(queries[query_counter].l, bit);
            query_counter++;
        }
    }
    for (int i=0; i<q; i++) cout<<ans[i]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q; cin>>n; int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    cin>>q;
    Query queries[q];
    for(int i=0;i<q;i++)
    {
        cin>>queries[i].l>>queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }
    sort(queries, queries+q, cmp);
    answeringQueries(ar, n, queries, q);
    return 0;
}

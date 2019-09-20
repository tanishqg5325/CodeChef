#include <bits/stdc++.h>
using namespace std;

struct node
{
    int maxf, suff_num, suff_freq, pre_num, pre_freq;
};

node mer(node &n1, node &n2)
{
    node res;
    res.suff_num = n2.suff_num;
    res.pre_num = n1.pre_num;
    if(n1.suff_num == n2.pre_num)
    {
        res.maxf = max(max(n1.maxf, n2.maxf), n1.suff_freq + n2.pre_freq);
        if(n1.pre_num == n1.suff_num) res.pre_freq = n1.pre_freq + n2.pre_freq;
        else res.pre_freq = n1.pre_freq;
        if(n2.suff_num == n2.pre_num) res.suff_freq = n2.suff_freq + n1.suff_freq;
        else res.suff_freq = n2.suff_freq;
    }
    else
    {
        res.maxf = max(n1.maxf, n2.maxf);
        res.suff_freq = n2.suff_freq;
        res.pre_freq = n1.pre_freq;
    }
    return res;
}

void constructST(int si, int ss, int se, int ar[], node st[])
{
    if(ss == se) {st[si] = {1, ar[ss], 1, ar[ss], 1}; return;}
    int mid = (ss + se)/2;
    constructST(2*si+1,ss,mid,ar,st);
    constructST(2*si+2,mid+1,se,ar,st);
    st[si] = mer(st[2*si+1], st[2*si+2]);
}

node solve(int si, int ss, int se, node st[], int l, int r)
{
    if(l == ss && r == se) return st[si];
    int mid = (ss + se)/2;
    if(l > mid) return solve(2*si+2, mid+1, se, st, l, r);
    if(r <= mid) return solve(2*si+1, ss, mid, st, l, r);
    node n1 = solve(2*si+1, ss, mid, st, l, mid), n2 = solve(2*si+2, mid+1, se, st, mid+1, r);
    return mer(n1, n2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,x,y; cin>>n;
    while(n)
    {
        cin>>q;
        int ar[n]; for(int i=0;i<n;i++) cin>>ar[i];
        x = (int)(ceil(log2(n)));
        y = (1<<(x+1)) - 1;
        node st[y]; constructST(0, 0, n-1, ar, st);
        while(q--)
        {
            cin>>x>>y;
            cout<<solve(0, 0, n-1, st, x-1, y-1).maxf<<"\n";
        }
        cin>>n;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sum,prefix,suffix,ans;
};

node mer(node n1, node n2)
{
    node res;
    res.sum = n1.sum + n2.sum;
    res.prefix = max(n1.prefix, n1.sum+n2.prefix);
    res.suffix = max(n2.suffix, n2.sum + n1.suffix);
    res.ans = max(max(n1.ans, n2.ans), n1.suffix + n2.prefix);
    return res;
}

void constructST(int si, int ss, int se, int ar[], node st[])
{
    if(ss == se) {st[si] = {ar[ss], ar[ss], ar[ss], ar[ss]}; return;}
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
    return mer(solve(2*si+1, ss, mid, st, l, mid), solve(2*si+2, mid+1, se, st, mid+1, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,x,y; cin>>n;
    int ar[n]; for(int i=0;i<n;i++) cin>>ar[i];
    x = (int)(ceil(log2(n)));
    y = (1<<(x+1)) - 1;
    node st[y]; constructST(0, 0, n-1, ar, st);
    cin>>q;
    while(q--)
    {
        cin>>x>>y; x--; y--;
        cout<<solve(0, 0, n-1, st, x, y).ans<<"\n";
    }
    return 0;
}

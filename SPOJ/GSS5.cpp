#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sum,prefix,suffix,ans;
};

int ar[100000], n; node st[300000];

node mer(node &n1, node &n2)
{
    node res;
    res.sum = n1.sum + n2.sum;
    res.prefix = max(n1.prefix, n1.sum + n2.prefix);
    res.suffix = max(n2.suffix, n2.sum + n1.suffix);
    res.ans = max(max(n1.ans, n2.ans), n1.suffix + n2.prefix);
    return res;
}

void constructST(int si, int ss, int se)
{
    if(ss == se) {st[si] = {ar[ss], ar[ss], ar[ss], ar[ss]}; return;}
    int mid = (ss + se)/2;
    constructST(2*si+1,ss,mid);
    constructST(2*si+2,mid+1,se);
    st[si] = mer(st[2*si+1], st[2*si+2]);
}

node solve(int si, int ss, int se, int l, int r)
{
    if(l == ss && r == se) return st[si];
    int mid = (ss + se)/2;
    if(l > mid) return solve(2*si+2, mid+1, se, l, r);
    if(r <= mid) return solve(2*si+1, ss, mid, l, r);
    node n1 = solve(2*si+1, ss, mid, l, mid), n2 = solve(2*si+2, mid+1, se, mid+1, r);
    return mer(n1, n2);
}

node solve(int l, int r)
{
    return solve(0, 0, n-1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,q,x1,y1,x2,y2,ans; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>ar[i];
        constructST(0, 0, n-1);
        cin>>q;
        while(q--)
        {
            cin>>x1>>y1>>x2>>y2;
            x1--; y1--; x2--; y2--;
            if(y1 <= x2)
                ans = solve(y1, x2).sum + solve(x1, y1).suffix + solve(x2, y2).prefix - ar[x2] - ar[y1];
            else
            {
                ans = solve(x1, x2).suffix + solve(x2, y1).sum + solve(y1, y2).prefix - ar[x2] - ar[y1];
                ans = max(ans, solve(x2, y1).suffix + solve(y1, y2).prefix - ar[y1]);
                ans = max(ans, solve(x1, x2).suffix + solve(x2, y1).prefix - ar[x2]);
                ans = max(ans, solve(x2, y1).ans);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}

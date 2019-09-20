#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n0,n1,n2,pending;
};

node st[262143];

void constructST(int si, int ss, int se)
{
    if(ss == se) {st[si] = {1, 0, 0, 0}; return;}
    int mid = (ss + se) >> 1;
    constructST(2*si+1, ss, mid);
    constructST(2*si+2, mid+1, se);
    st[si] = {se - ss + 1, 0, 0, 0};
}

void updateChildren(int si, int v)
{
    st[2*si+1].pending = (st[2*si+1].pending + v) % 3;
    st[2*si+2].pending = (st[2*si+2].pending + v) % 3;
}

int solve(int si, int ss, int se, int l, int r)
{
    if(st[si].pending)
    {
        if(ss != se) updateChildren(si, st[si].pending);
        if(st[si].pending == 1) st[si] = {st[si].n2, st[si].n0, st[si].n1, 0};
        else st[si] = {st[si].n1, st[si].n2, st[si].n0, 0};
    }
    if(l == ss && r == se) return st[si].n0;
    int mid = (ss + se) >> 1;
    if(l > mid) return solve(2*si+2, mid+1, se, l, r);
    if(r <= mid) return solve(2*si+1, ss, mid, l, r);
    return solve(2*si+1, ss, mid, l, mid) + solve(2*si+2, mid+1, se, mid+1, r);
}

void update(int si, int ss, int se, int l, int r, int v)
{
    if(ss == l && se == r) {st[si].pending = (st[si].pending + v) % 3; return;}
    int mid = (ss + se) >> 1;
    if(l > mid) update(2*si+2, mid+1, se, l, r, v);
    else if(r <= mid) update(2*si+1, ss, mid, l, r, v);
    else
    {
        update(2*si+1, ss, mid, l, mid, v);
        update(2*si+2, mid+1, se, mid+1, r, v);
    }
    if(st[2*si+1].pending == 0)
    {
        st[si].n0 = st[2*si+1].n0;
        st[si].n1 = st[2*si+1].n1;
        st[si].n2 = st[2*si+1].n2;
    }
    else if(st[2*si+1].pending == 1)
    {
        st[si].n0 = st[2*si+1].n2;
        st[si].n1 = st[2*si+1].n0;
        st[si].n2 = st[2*si+1].n1;
    }
    else if(st[2*si+1].pending == 2)
    {
        st[si].n0 = st[2*si+1].n1;
        st[si].n1 = st[2*si+1].n2;
        st[si].n2 = st[2*si+1].n0;
    }
    if(st[2*si+2].pending == 0)
    {
        st[si].n0 += st[2*si+2].n0;
        st[si].n1 += st[2*si+2].n1;
        st[si].n2 += st[2*si+2].n2;
    }
    else if(st[2*si+2].pending == 1)
    {
        st[si].n0 += st[2*si+2].n2;
        st[si].n1 += st[2*si+2].n0;
        st[si].n2 += st[2*si+2].n1;
    }
    else if(st[2*si+2].pending == 2)
    {
        st[si].n0 += st[2*si+2].n1;
        st[si].n1 += st[2*si+2].n2;
        st[si].n2 += st[2*si+2].n0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,x,y,k;
    cin>>n>>q;
    constructST(0, 0, n-1);
    while(q--)
    {
        cin>>k>>x>>y;
        if(k == 0) update(0, 0, n-1, x, y, 1);
        else cout<<solve(0, 0, n-1, x, y)<<"\n";
    }
    return 0;
}

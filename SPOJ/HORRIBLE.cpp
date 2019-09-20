#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

struct node
{
    ll val, pending;
};

node st[262143];

void constructST(int si, int ss, int se)
{
    if(ss == se) {st[si] = {0, 0}; return;}
    int mid = (ss + se) >> 1;
    constructST(2*si+1, ss, mid);
    constructST(2*si+2, mid+1, se);
    st[si] = {0, 0};
}

void updateChildren(int si, ll v)
{
    st[2*si+1].pending += v;
    st[2*si+2].pending += v;
}

ll solve(int si, int ss, int se, int l, int r)
{
    if(st[si].pending > 0)
    {
        st[si].val += st[si].pending * (se - ss + 1);
        if(ss != se) updateChildren(si, st[si].pending);
        st[si].pending = 0;
    }
    if(l == ss && r == se) return st[si].val;
    int mid = (ss + se) >> 1;
    if(l > mid) return solve(2*si+2, mid+1, se, l, r);
    if(r <= mid) return solve(2*si+1, ss, mid, l, r);
    return solve(2*si+1, ss, mid, l, mid) + solve(2*si+2, mid+1, se, mid+1, r);
}

void update(int si, int ss, int se, int l, int r, ll v)
{
    if(ss == l && se == r) {st[si].pending += v; return;}
    int mid = (ss + se) >> 1;
    if(l > mid) update(2*si+2, mid+1, se, l, r, v);
    else if(r <= mid) update(2*si+1, ss, mid, l, r, v);
    else
    {
        update(2*si+1, ss, mid, l, mid, v);
        update(2*si+2, mid+1, se, mid+1, r, v);
    }
    st[si].val = st[2*si+1].val + st[2*si+2].val + st[2*si+1].pending * (mid - ss + 1) + st[2*si+2].pending * (se - mid);
}

int main()
{
    int t,n,q,x,y,k; ll v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &q);
        constructST(0, 0, n-1);
        while(q--)
        {
            scanf("%d %d %d", &k, &x, &y); x--; y--;
            if(k == 0) {scanf("%lld", &v); update(0, 0, n-1, min(x, y), max(x, y), v);}
            else printf("%lld\n", solve(0, 0, n-1, min(x, y), max(x, y)));
        }
    }
    return 0;
}

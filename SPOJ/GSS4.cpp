#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void constructST(int si, int ss, int se, ll ar[], ll st[])
{
    if(ss == se) {st[si] = ar[ss]; return;}
    int mid = (ss + se) >> 1;
    constructST(2*si+1,ss,mid,ar,st);
    constructST(2*si+2,mid+1,se,ar,st);
    st[si] = st[2*si+1] + st[2*si+2];
}

ll solve(int si, int ss, int se, ll st[], int l, int r)
{
    if(l == ss && r == se) return st[si];
    int mid = (ss + se) >> 1;
    if(l > mid) return solve(2*si+2, mid+1, se, st, l, r);
    if(r <= mid) return solve(2*si+1, ss, mid, st, l, r);
    return solve(2*si+1, ss, mid, st, l, mid) + solve(2*si+2, mid+1, se, st, mid+1, r);
}

void lazy(int si, ll st[], int ss, int se)
{
    if(st[si] <= se - ss + 1) return;
    if(ss == se) {st[si] = (ll)sqrt(st[si]); return;}
    int mid = (ss + se) >> 1;
    lazy(2*si+1, st, ss, mid);
    lazy(2*si+2, st, mid+1, se);
    st[si] = st[2*si+1] + st[2*si+2];
}

void update(int si, ll st[], int ss, int se, int l, int r)
{
    if(ss == l && se == r) {lazy(si, st, ss, se); return;}
    int mid = (ss + se) >> 1;
    if(l > mid) update(2*si+2, st, mid+1, se, l, r);
    else if(r <= mid) update(2*si+1, st, ss, mid, l, r);
    else
    {
        update(2*si+1, st, ss, mid, l, mid);
        update(2*si+2, st, mid+1, se, mid+1, r);
    }
    st[si] = st[2*si+1] + st[2*si+2];
}

/*
//range update in O(n)
void update(int si, ll st[], int ss, int se, int l, int r)
{
    if(ss == se) {st[si] = (ll)sqrt(st[si]); return;}
    int mid = (ss + se) >> 1;
    if(l > mid) update(2*si+2, st, mid+1, se, l, r);
    else if(r <= mid) update(2*si+1, st, ss, mid, l, r);
    else
    {
        update(2*si+1, st, ss, mid, l, mid);
        update(2*si+2, st, mid+1, se, mid+1, r);
    }
    st[si] = st[2*si+1] + st[2*si+2];
}*/

ll ar[100000], st[262143];

int main()
{
    int n,q,x,y,k,t=1;
    while(scanf("%d", &n) != EOF)
    {
        printf("Case #%d:\n", t);
        for(int i=0;i<n;i++) scanf("%lld", &ar[i]);
        constructST(0, 0, n-1, ar, st);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d %d", &k, &x, &y); x--; y--;
            if(k == 1) printf("%lld\n", solve(0, 0, n-1, st, min(x, y), max(x, y)));
            else update(0, st, 0, n-1, min(x, y), max(x, y));
        }
        t++; printf("\n");
    }
    return 0;
}

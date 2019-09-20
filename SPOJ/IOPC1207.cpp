#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;
typedef long long ll;

struct node
{
    int val;
    bool pending;
} stx[MAXN], sty[MAXN], stz[MAXN];

void constructST(int si, node st[], int ss, int se)
{
    if(ss == se) {st[si] = {0, 0}; return;}
    int mid = (ss + se) >> 1;
    constructST(2*si+1, st, ss, mid);
    constructST(2*si+2, st, mid+1, se);
    st[si] = {0, 0};
}

void updateChildren(node st[], int si)
{
    st[2*si+1].pending ^= 1;
    st[2*si+2].pending ^= 1;
}

int solve(int si, node st[], int ss, int se, int l, int r)
{
    if(st[si].pending)
    {
        st[si].val = se - ss + 1 - st[si].val;
        if(ss != se) updateChildren(st, si);
        st[si].pending = 0;
    }
    if(l == ss && r == se) return st[si].val;
    int mid = (ss + se) >> 1;
    if(l > mid) return solve(2*si+2, st, mid+1, se, l, r);
    if(r <= mid) return solve(2*si+1, st, ss, mid, l, r);
    return solve(2*si+1, st, ss, mid, l, mid) + solve(2*si+2, st, mid+1, se, mid+1, r);
}

void update(int si, node st[], int ss, int se, int l, int r)
{
    if(ss == l && se == r) {st[si].pending ^= 1; return;}
    int mid = (ss + se) >> 1;
    if(l > mid) update(2*si+2, st, mid+1, se, l, r);
    else if(r <= mid) update(2*si+1, st, ss, mid, l, r);
    else
    {
        update(2*si+1, st, ss, mid, l, mid);
        update(2*si+2, st, mid+1, se, mid+1, r);
    }
    if(st[2*si+1].pending) st[si].val = mid - ss + 1 - st[2*si+1].val;
    else st[si].val = st[2*si+1].val;
    if(st[2*si+2].pending) st[si].val += se - mid - st[2*si+2].val;
    else st[si].val += st[2*si+2].val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,nx,ny,nz,q,k,x1,y1,z1,x2,y2,z2,l,r;
    ll rx,ry,rz,gx,gy,gz,ans; cin>>t;
    while(t--)
    {
        cin>>nx>>ny>>nz>>q;
        constructST(0, stx, 0, nx-1);
        constructST(0, sty, 0, ny-1);
        constructST(0, stz, 0, nz-1);
        while(q--)
        {
            cin>>k;
            if(k == 0)
            {
                cin>>l>>r;
                update(0, stx, 0, nx-1, l, r);
            }
            else if(k == 1)
            {
                cin>>l>>r;
                update(0, sty, 0, ny-1, l, r);
            }
            else if(k == 2)
            {
                cin>>l>>r;
                update(0, stz, 0, nz-1, l, r);
            }
            else
            {
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                rx = solve(0, stx, 0, nx-1, x1, x2);
                ry = solve(0, sty, 0, ny-1, y1, y2);
                rz = solve(0, stz, 0, nz-1, z1, z2);
                gx = x2 - x1 + 1 - rx;
                gy = y2 - y1 + 1 - ry;
                gz = z2 - z1 + 1 - rz;
                ans = rx * gy * gz + gx * ry * gz + gx * gy * rz + rx * ry * rz;
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}

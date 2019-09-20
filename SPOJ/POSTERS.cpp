#include <bits/stdc++.h>
using namespace std;

void update(int si, int st[], int l, int r, int val, int ss, int se)
{
    if(ss == l && se == r) {st[si] = val; return;}
    int mid = (ss + se) >> 1;
    if(st[si])
    {
        st[2*si+1] = st[2*si+2] = st[si];
        st[si] = 0;
    }
    if(l > mid) update(2*si+2, st, l, r, val, mid+1, se);
    else if(r <= mid) update(2*si+1, st, l, r, val, ss, mid);
    else
    {
        update(2*si+1, st, l, mid, val, ss, mid);
        update(2*si+2, st, mid+1, r, val, mid+1, se);
    }
}

void ans(int si, int st[], int ss, int se, bool colors[])
{
    if(ss == se) {colors[st[si]] = 1; return;}
    int mid = (ss + se) >> 1;
    if(st[si])
    {
        st[2*si+1] = st[2*si+2] = st[si];
        st[si] = 0;
    }
    ans(2*si+1, st, ss, mid, colors);
    ans(2*si+2, st, mid+1, se, colors);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,x,y; cin>>T;
    while(T--)
    {
        cin>>n; int l[n],r[n];
        int k = 0;
        for(int i=0;i<n;i++) {cin>>l[i]>>r[i]; k = max(k, max(l[i], r[i]));}
        x = (int)(ceil(log2(k+1))); y = (1<<(x+1)) - 1;
        int st[y]{};
        for(int i=0;i<n;i++)
            update(0, st, l[i], r[i], i+1, 0, k);
        bool colors[n+1]{};
        ans(0, st, 0, k, colors);
        int res = 0;
        for(int i=1;i<=n;i++) if(colors[i]) res++;
        cout<<res<<"\n";
    }
    return 0;
}

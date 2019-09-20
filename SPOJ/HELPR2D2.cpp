#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int solve(int si, int ss, int se, int st[], int val)
{
    if(ss == se) return ss;
    int mid = (ss + se)/2;
    if(st[2*si+1] <= val) return solve(2*si+1, ss, mid, st, val);
    else return solve(2*si+2, mid+1, se, st, val);
}

void update(int si, int st[], int ss, int se, int idx, int val)
{
    if(ss == se) {st[si] += val; return;}
    int mid = (ss + se)/2;
    if(idx <= mid) update(2*si+1, st, ss, mid, idx, val);
    else update(2*si+2, st, mid+1, se, idx, val);
    st[si] = min(st[2*si+1], st[2*si+2]);
}

pii ans(int si, int st[], int ss, int se)
{
    if(ss == se)
    {
        if(st[si]) return {1, st[si]};
        else return {0, 0};
    }
    int mid = (ss + se) / 2;
    pii p1 = ans(2*si+1, st, ss, mid);
    pii p2 = ans(2*si+2, st, mid+1, se);
    return {p1.X + p2.X, p1.Y + p2.Y};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,k,q,r,v,idx; string str; cin>>t;
    while(t--)
    {
        int st[300000]{}; int ar[100000]{};
        cin>>k>>q;
        while(q)
        {
            cin>>str;
            if(!str.compare("b"))
            {
                cin>>r>>v; q -= r;
                while(r)
                {
                    idx = solve(0, 0, 99999, st, k-v);
                    int tmp = (k - ar[idx]) / v;
                    if(tmp <= r) {update(0, st, 0, 99999, idx, tmp*v); ar[idx] += tmp*v; r-= tmp;}
                    else {update(0, st, 0, 99999, idx, r*v); ar[idx] += r*v; r=0;}
                }
            }
            else
            {
                v = stoi(str); q--;
                idx = solve(0, 0, 99999, st, k-v);
                ar[idx] += v;
                update(0, st, 0, 99999, idx, v);
            }
        }
        pii p = ans(0, st, 0, 99999);
        cout<<p.X<<" "<<k*p.X - p.Y<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int st[300000];

void constructST(int st[], int si, int ss, int se, int ar[])
{
    if(ss == se) {st[si] = ar[ss]; return;}
    int mid = (ss + se) >> 1;
    constructST(st, 2*si+1, ss, mid, ar);
    constructST(st, 2*si+2, mid+1, se, ar);
    st[si] = st[2*si+1] || st[2*si+2];
}

bool ans(int st[], int si, int ss, int se, int l, int r)
{
    if(ss == l && se == r) return st[si];
    int mid = (ss + se) >> 1;
    if(l > mid) return ans(st, 2*si+2, mid+1, se, l, r);
    else if(r <= mid) return ans(st, 2*si+1, ss, mid, l, r);
    return ans(st, 2*si+1, ss, mid, l, mid) || ans(st, 2*si+2, mid+1, se, mid+1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,q,l,r; string str; cin>>T;
    while(T--)
    {
        cin>>n>>q>>str;
        if(n >= 3)
        {
            int ar[n-2];
            for(int i=0;i<n-2;i++)
            {
                if(str[i] != str[i+1] && str[i] != str[i+2] && str[i+1] != str[i+2]) ar[i] = 0;
                else ar[i] = 1;
            }
            constructST(st, 0, 0, n-3, ar);
        }
        while(q--)
        {
            cin>>l>>r; r -= 2;
            if(r < l || n < 3) {cout<<"NO\n"; continue;}
            l--; r--;
            if(ans(st, 0, 0, n-3, l, r)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}

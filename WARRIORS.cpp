#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll mod = 1000000007;
ll inf = 2000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,q,ans; cin>>T;
    while(T--)
    {
        cin>>n>>q; int p[n];
        for(int i=0;i<n;i++) cin>>p[i];
        sort(p, p+n); pii qu[q]; int ans[q];
        for(int i=0;i<q;i++)
        {
            cin>>qu[i].X;
            qu[i].Y = i;
        }
        sort(qu, qu+q);
        ll curr_pow = 0, init_pow = 0, h, one = 1, tmp; int k = 0;
        for(int i=0;i<q;i++)
        {
            h = qu[i].X - init_pow;
            if(h > 0)
            {
                if(k >= 31) tmp = inf;
                else tmp = min((one << k) * h, inf);
                curr_pow = min(curr_pow + tmp, inf);
            }
            while(k < n && curr_pow > p[k])
            {
                curr_pow -= p[k++];
                curr_pow = min(curr_pow * 2, inf);
            }
            ans[qu[i].Y] = k;
            init_pow = qu[i].X;
        }
        for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
    }
    return 0;
}

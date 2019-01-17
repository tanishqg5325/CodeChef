#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define X first
#define Y second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,l,r; cin>>n;
    ll dist[n][n]{},ans; pll p[n];
    for(int i=0;i<n;i++) cin>>p[i].X>>p[i].Y;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            dist[i][j] = max(dist[i][j-1], (p[i].X - p[j].X) * (p[i].X - p[j].X) + (p[i].Y - p[j].Y) * (p[i].Y - p[j].Y));
    cin>>q;
    while(q--)
    {
        cin>>l>>r; l--; r--; ans = 0;
        for(int i=l;i<=r;i++) ans = max(ans, dist[i][r]);
        cout<<ans<<"\n";
    }
    return 0;
}

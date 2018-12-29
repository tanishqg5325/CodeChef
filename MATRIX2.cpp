#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m; cin>>n>>m; char c;
    ll dp[n][m], tmp[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {cin>>c; tmp[i][j] = dp[i][j] = c - '0';}
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(!tmp[i][j]) continue;
            tmp[i][j] = 1 + tmp[i-1][j];
        }
    }
    ll ans = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(!dp[i][j]) continue;
            dp[i][j] = 1 + min(dp[i-1][j-1], tmp[i-1][j]);
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans += dp[i][j];
    cout<<ans<<"\n";
	return 0;
}

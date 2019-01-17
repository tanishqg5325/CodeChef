#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,ans; string str;
    cin>>T;
    while(T--)
    {
        cin>>str; string rev;
        n = str.size(); int dp[n+1][n+1]{};
        for(int i=n-1;i>=0;i--) rev += str[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i-1] == rev[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        ans = n;
        for(int i=0;i<=n;i++)
            ans = min(ans, n - 2*dp[i][n-i]);
        for(int i=0;i<n;i++)
            ans = min(ans, n-1-2*dp[i][n-1-i]);
        cout<<ans<<"\n";
    }
    return 0;
}

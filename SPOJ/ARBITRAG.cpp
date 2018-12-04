#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1,n,m,i; string str,str1,str2; double d;
    cin>>n;
    while(n)
    {
        double dp[n][n];
        memset(dp, 0, sizeof(dp));
        unordered_map<string, int> curr;
        for(int i=0;i<n;i++) {cin>>str; curr[str] = i;}
        cin>>m;
        for(int i=0;i<n;i++) dp[i][i] = 1;
        while(m--)
        {
            cin>>str1>>d>>str2;
            dp[curr[str1]][curr[str2]] = d;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
        for(i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dp[i][j] * dp[j][i] > 1)
                    i = j = n+1;
        cout<<"Case "<<t<<": ";
        if(i == n) cout<<"No\n";
        else cout<<"Yes\n";
        cin>>n; t++;
    }
    return 0;
}

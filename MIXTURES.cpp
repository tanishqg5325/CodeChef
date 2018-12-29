#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int ar[n]; for(int i=0;i<n;i++) cin>>ar[i];
        pii dp[n][n];
        for(int i=0;i<n;i++) dp[i][i] = {ar[i], 0}; // {colour, smoke}
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[j][i].X = (dp[j][j].X + dp[j+1][i].X) % 100;
                dp[j][i].Y = dp[j][j].Y + dp[j+1][i].Y + dp[j][j].X * dp[j+1][i].X;
                for(int k=j+1;k<i;k++)
                {
                    if(dp[j][k].Y + dp[k+1][i].Y + dp[j][k].X * dp[k+1][i].X < dp[j][i].Y)
                    {
                        dp[j][i].Y = dp[j][k].Y + dp[k+1][i].Y + dp[j][k].X * dp[k+1][i].X;
                        dp[j][i].X = (dp[j][k].X + dp[k+1][i].X) % 100;
                    }
                    else if(dp[j][k].Y + dp[k+1][i].Y + dp[j][k].X * dp[k+1][i].X == dp[j][i].Y)
                        dp[j][i].X = min(dp[j][i].X, (dp[j][k].X + dp[k+1][i].X) % 100);
                }
            }
        }
        cout<<dp[0][n-1].Y<<"\n";
    }
	return 0;
}


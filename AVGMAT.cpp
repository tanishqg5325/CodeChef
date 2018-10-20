#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m; char c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m; bool ar[n][m]{}; int dp[n+m-1]{};
        for(int i=0;i<n;i++) { for(int j=0;j<m;j++){cin>>c; if(c == '1') ar[i][j]=1;} }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!ar[i][j]) continue;
                for(int k=j+1;k<m;k++) if(ar[i][k]) dp[k-j]++;
                for(int k=i+1;k<n;k++)
                    for(int l=0;l<m;l++)
                        if(ar[k][l]) dp[k-i+abs(l-j)]++;
            }
        }
        for(int i=1;i<n+m-1;i++) cout<<dp[i]<<" "; cout<<"\n";
    }
    return 0;
}

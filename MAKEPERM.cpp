#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n; ans=0;
        int ar[n]; bool dp[n+1];
        for(int i=0;i<n;i++) {cin>>ar[i]; dp[i]=0;} dp[n]=0;
        for(int i=0;i<n;i++)
        {
            if(ar[i]<=n && dp[ar[i]]==0) dp[ar[i]]=1, ans++;
        }
        cout<<n-ans<<"\n";
    }
    return 0;
}

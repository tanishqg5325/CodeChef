#include <iostream>

using namespace std;

int main()
{
    int t,n,max;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n],dp[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        dp[0]=max=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(ar[j]<=ar[i] && dp[j]>=dp[i])
                    dp[i]=dp[j]+1;
            }
            if(dp[i]>max)
                max=dp[i];
        }
        cout<<max<<endl;
    }
    return 0;
}

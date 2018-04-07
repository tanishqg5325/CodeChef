#include <iostream>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        int dp[n];
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if((ar[i]>0 && ar[i+1]<0) || (ar[i]<0 && ar[i+1]>0))
                dp[i]=dp[i+1]+1;
            else
                dp[i]=1;
        }
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}

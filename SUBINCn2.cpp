#include <iostream>

using namespace std;

int main()
{
    int t,n;
    long long count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        bool dp[n][n]{};
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
            cin>>ar[i];
        }
        count=n;
        for(int i=1;i<n;i++)
            for(int j=0;j<n-i;j++)
                if(dp[j][i-1] && ar[i+j-1]<=ar[i+j])
                {
                    dp[j][i]=1;
                    count++;
                }
        cout<<count<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>ar[i][j];
        ans=ar[0][0];
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
                ar[i][j]+=ar[i-1][j-1]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ans<ar[i][j])
                    ans=ar[i][j];
        cout<<ans<<endl;
    }
    return 0;
}

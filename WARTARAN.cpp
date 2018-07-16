#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        bool m[n][n];
        int sum,maxsum=0,robo=0,tmp,x,y,c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }
        int dp1[n+1];
        for(int i=0;i<n;i++) cout<<1<<" ";
        int dp2[n+1],k2,k1;
        cout<<endl;
        cout.flush();
        for(int i=1;i<=n;i++) {cin>>dp2[i]; dp1[i]=1; }
        c=n/(a+b);
        k2=k1=1;
        while(c--)
        {
            for(int i=0;i<a;i++)
            {
                while(dp2[k2]==0) k2++;
                while(dp1[k1]==0) k1++;
                cout<<k1<<" "<<k2<<endl;
                dp2[k2]--;
                dp1[k1]--;
                cout.flush();
            }
            for(int i=0;i<b;i++)
                cin>>x>>y, dp2[y]--, dp1[x]--;
        }
    }
    return 0;
}

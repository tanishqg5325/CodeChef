#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,qu,l,r; ll ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int p[n+1][m+1],q[n+1][m+1];
        for(int i=1;i<=m;i++) q[0][i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>p[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                q[i][j]=p[i][q[i-1][j]];
        cin>>qu;
        while(qu--)
        {
            cin>>l>>r;
            ans=0;
            for(int i=1;i<=m;i++) ans+=(q[r][i]*q[l-1][i]);
            cout<<ans<<endl;
        }
    }
    return 0;
}

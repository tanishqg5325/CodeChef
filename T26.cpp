#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,l,r,q,k;
    cin>>n>>m;
    int choco[n]{},dp[m+1]{};
    for(int i=0;i<m;i++)
    {
        cin>>l>>r; l--; r--;
        for(int i=l;i<=r;i++)
            choco[i]++,dp[choco[i]]++;
    }
    cin>>q;
    while(q--)
    {
        cin>>k;
        if(k<=m) cout<<dp[k]<<"\n";
        else cout<<"0\n";
    }
    return 0;
}

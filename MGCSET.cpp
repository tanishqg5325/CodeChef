#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,a,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=0;i<n;i++) {cin>>a; if(a%m==0) ans++;}
        ans = (int)(pow(2,ans)-1);
        cout<<ans<<endl;
    }
    return 0;
}

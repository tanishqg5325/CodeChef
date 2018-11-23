#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n; ans=0;
        int s[n],j[n];
        for(int i=0;i<n;i++) {cin>>s[i]>>j[i]; if(j[i]-s[i]>5) ans++;}
        cout<<ans<<"\n";
    }
    return 0;
}

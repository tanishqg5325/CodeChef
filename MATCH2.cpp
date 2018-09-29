#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,q,x,y,z,l,r,c,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>q; ans=0;
        int a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) {cin>>b[i]; if(b[i] == a[i]) ans++; }
        while(q--)
        {
            cin>>x>>y>>z;
            l = x ^ ans; r = y ^ ans; c = z ^ ans;
            l--; r--;
            for(int i=l;i<=r;i++)
                {if(a[i] == b[i]) ans--; a[i]=c; if(a[i]==b[i]) ans++;}
            cout<<ans<<"\n";
        }
    }
    return 0;
}

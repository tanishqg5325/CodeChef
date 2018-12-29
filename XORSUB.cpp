#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        bool xoru[1024]{}; xoru[0] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<1024;j++)
            {
                if(xoru[j]) xoru[ar[i] ^ j] = 1;
            }
        }
        int ans = k;
        for(int i=1;i<1024;i++) if(xoru[i]) ans = max(ans, k^i);
        cout<<ans<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        sort(ar,ar+n);
        int ans = ar[1]-ar[0];
        for(int i=1;i<n-1;i++)
            ans = min(ans, ar[i+1]-ar[i]);
        cout<<ans<<"\n";
    }
    return 0;
}

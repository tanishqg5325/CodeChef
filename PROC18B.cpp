#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n; double ans;
    cin>>t;
    cout<<fixed;
    cout<<setprecision(8);
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        sort(ar,ar+n,greater<int>());
        ans = (ar[0]+ar[1])/2;
        for(int i=2;i<n;i++) ans = (ans+ar[i])/2;
        cout<<ans<<"\n";
    }
    return 0;
}

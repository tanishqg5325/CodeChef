#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int s[n];
        for(int i(0);i<n;i++) cin>>s[i];
        sort(s,s+n,greater<int>());
        int ans = k;
        while(ans < n && s[ans] == s[k-1]) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}

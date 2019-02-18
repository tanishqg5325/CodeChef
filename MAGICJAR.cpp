#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; ll ans,a; cin>>T;
    while(T--)
    {
        cin>>n; ans = 0;
        for(int i=0;i<n;i++) {cin>>a; ans += a;}
        cout<<ans - n + 1<<"\n";
    }
    return 0;
}

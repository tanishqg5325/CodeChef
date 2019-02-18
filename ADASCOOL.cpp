#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m; cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(n%2 && m%2) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

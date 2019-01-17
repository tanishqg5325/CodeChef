#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; ll n,p,ans; cin>>T;
    while(T--)
    {
        cin>>n>>p;
        if(n == 1 || n == 2) ans = p*p*p;
        else ans = (p - (n-1)/2)*(p - (n-1)/2) + (p - n) * (p - (n-1)/2) + (p - n) * (p - n);
        cout<<ans<<"\n";
    }
    return 0;
}

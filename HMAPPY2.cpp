#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; ll n,a,b,k,l; cin>>T;
    while(T--)
    {
        cin>>n>>a>>b>>k;
        l = a*b/__gcd(a,b);
        if(n/a + n/b - 2*(n/l) >= k) cout<<"Win\n";
        else cout<<"Lose\n";
    }
    return 0;
}

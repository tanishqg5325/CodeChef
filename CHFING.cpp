#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; ll n,k,a,b,ans; cin>>T;
    while(T--)
    {
        cin>>n>>k;
        a = (k-1)/(n-1);
        a = a % mod; n--; n = n % mod;
        b = (n * a) % mod;
        b = (k - 1 + mod - b) % mod;
        ans = ((a + 1) * b) % mod;
        b = (a*(a+1)/2) % mod;
        b = (n * b) % mod;
        ans = (ans + b) % mod;
        cout<<ans<<"\n";
    }
    return 0;
}

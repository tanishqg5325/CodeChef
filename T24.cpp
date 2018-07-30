#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a = 1000000007;

ll power(ll x, ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll tmp = power(x,n/2);
        tmp = (tmp*tmp)%a;
        return tmp;
    }
    ll tmp = power(x,(n-1)/2);
    tmp = (tmp*tmp)%a;
    tmp = (tmp*x)%a;
    return tmp;
}

ll mod_inv(ll x, ll y)
{
    if (y == 0) return 1;
    ll p = mod_inv(x,y/2)%a;
    p = (p*p)%a;
    return (y%2 == 0)?p:(x*p)%a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; ll n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1){cout<<1<<"\n"; continue;}
        ans = power(k,n+1);
        ans = (ans + a - k)%a;
        ans = (ans*mod_inv(k-1,a-2))%a;
        cout<<ans<<"\n";
    }
    return 0;
}

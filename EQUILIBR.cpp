#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a = 1000000007;

ll mod_inv(ll x, ll y)
{
    if (y == 0) return 1;
    ll p = mod_inv(x,y/2)%a;
    p = (p*p)%a;
    return (y%2 == 0)?p:(x*p)%a;
}

ll power(int x, ll n)
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

int main()
{
    int n,k,tmp; ll p,q,ans,two,t1;
    cin>>n>>k;
    tmp=n;
    two=0;
    while(tmp%2==0) {tmp/=2; two++;}
    t1 = n/power(2,two);
    q = power(2,n-1-two);
    p = (q+a-t1)%a;
    ans = (p*mod_inv(q,a-2))%a;
    cout<<ans<<"\n";
    return 0;
}

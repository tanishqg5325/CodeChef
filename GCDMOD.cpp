#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

ll gcd(ll a, ll b) {if(b==0) return a; return gcd(b,a%b);}

ll multiply(ll a, ll b, ll c)
{
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;
    ll a2 = multiply(a, b/2,c);
    if (b%2 == 0) return (a2 + a2) % c;
    return ((a % c) + (a2 + a2)) % c;
}

ll power(ll x, ll n, ll m)
{
    if(n==0) return (1%m);
    if(n%2==0)
    {
        ll tmp = power(x,n/2,m);
        return multiply(tmp,tmp,m);
    }
    ll tmp = power(x,(n-1)/2,m);
    tmp = multiply(tmp,tmp,m);
    return multiply(tmp,x,m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; ll a,b,c,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        c = abs(a - b);
        if(c == 0)
        {
            ll a1 = power(a%mod,n,mod); ll b1 = power(b%mod,n,mod);
            cout<<(a1+b1)%mod<<"\n";
            continue;
        }
        ll a1 = power(a%c,n,c); ll b1 = power(b%c,n,c);
        a1 = (a1 + b1)%c;
        cout<<gcd(c,a1)%mod<<"\n";
    }
}

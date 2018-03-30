#include <iostream>

using namespace std;

long gcd(long m,long n)
{
    if(m%n==0)
        return n;
    else
        return gcd(n,m%n);
}

int main()
{
    long t,a,b,ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ans=gcd(a,b);
        cout<<ans<<" "<<a*b/ans<<endl;
    }
    return 0;
}

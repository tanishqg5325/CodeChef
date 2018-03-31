#include <iostream>

using namespace std;

int gcd(int m,int n)
{
    if(m%n==0)
        return n;
    else
        return gcd(n,m%n);
}

int main()
{
    int t,n,m,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        a=gcd(n,m);
        cout<<(n*m)/(a*a)<<endl;
    }
    return 0;
}

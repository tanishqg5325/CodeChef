#include <iostream>
using namespace std;

long long a=1000000007;

long long power(long long n)
{
    if(n==0)
        return 1;
    long long temp;
    if(n%2==0)
    {
        temp = power(n/2);
        temp = (temp * temp) % a;
        return temp;
    }
    temp = power((n-1)/2);
    temp = (temp * temp) % a;
    temp = (temp*10)%a;
    return temp;
}

int main()
{
    int t,w;
    long long n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        if(w>8 || w<-9)
            cout<<0<<endl;
        else
        {
            if(w>=0)
                w=9-w;
            else
                w=10+w;
            ans=(power(n-2)*w)%a;
            cout<<ans<<endl;
        }
    }
    return 0;
}

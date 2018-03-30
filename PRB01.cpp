#include <iostream>

using namespace std;

int isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(isPrime(n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

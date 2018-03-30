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
    int t,n,ar[50],hcf;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>ar[i];
        hcf=ar[0];
        for(int i=1;i<n;i++)
            hcf=gcd(ar[i],hcf);
        for(int i=0;i<n;i++)
            cout<<ar[i]/hcf<<" ";
        cout<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long long n,k,sum,a=1000000007;
    cin>>n>>k;
    if(n<=k || k==1)
        cout<<1<<endl;
    else
    {
        int ar[n];
        for(int i=0;i<k;i++)
            ar[i]=1;
        sum=k;
        for(int i=k;i<n;i++)
        {
            ar[i]=sum;
            sum = (sum*2 - ar[i-k])%a;
        }
        cout<<ar[n-1];
    }
    return 0;
}


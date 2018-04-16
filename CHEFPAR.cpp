#include <iostream>
using namespace std;

int main()
{
    long long n,m,k,temp,max=0,ans=0;
    cin>>n>>m>>k;
    long long ar[n],p[m];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<m;i++)
        cin>>p[i];
    for(int i=0;i<=k;i++)
    {
        temp=1;
        for(int a=0;a<n;a++)
            temp=(temp*(ar[a]+i))%p[m-1];
        if(temp>max)
        {
            max=temp;
            ans=i;
        }
    }
    for(int i=0;i<n;i++)
        cout<<ar[i]+ans<<" ";
    return 0;
}

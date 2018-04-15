#include <iostream>
using namespace std;

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    long long ar[n],p[m];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<m;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cout<<ar[i]+k<<" ";
    return 0;
}

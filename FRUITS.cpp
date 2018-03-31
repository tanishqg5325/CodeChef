#include <iostream>

using namespace std;

int abs(int a)
{
    if(a>=0)
        return a;
    return -a;
}

int main()
{
    int t,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cout<<max(abs(n-m)-k,0)<<endl;
    }
    return 0;
}

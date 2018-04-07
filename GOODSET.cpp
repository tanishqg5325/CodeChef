#include <iostream>

using namespace std;

int main()
{
    int t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<1<<" ";
        if(n==1)
        {
            cout<<endl;
            continue;
        }
        cout<<2<<" ";
        a=4;
        for(int i=0;i<n-2;i++)
        {
            cout<<a<<" ";
            a+=3;
        }
        cout<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long t,n,min,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a;
        min=a;
        for(long i=1;i<n;i++)
        {
            cin>>a;
            if(a<min)
                min=a;
        }
        cout<<min*(n-1)<<endl;
    }
    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t,n,a,x,y,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=floor(sqrt(n));
        for(i=a;i>=1;i--)
            if(n%i==0)
                break;
        x=i;
        y=n/i;
        for(i=0;i<x;i++)
            cout<<"X";
        for(i=0;i<y;i++)
            cout<<"D";
        cout<<endl;
    }
    return 0;
}

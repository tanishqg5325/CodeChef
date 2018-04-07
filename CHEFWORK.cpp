#include <iostream>

using namespace std;

int main()
{
    int n,min1,min2,min3,t;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    min1=min2=min3=2000000;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==1 && c[i]<min1)
            min1=c[i];
        else if(t==2 && c[i]<min2)
            min2=c[i];
        else if(t==3 && c[i]<min3)
            min3=c[i];
    }
    cout<<min(min1+min2,min3);
    return 0;
}

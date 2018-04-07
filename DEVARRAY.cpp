#include <iostream>

using namespace std;

int main()
{
    int n,q,t,min,max;
    cin>>n>>q;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    min=max=ar[0];
    for(int i=1;i<n;i++)
    {
        if(ar[i]>max)
            max=ar[i];
        if(ar[i]<min)
            min=ar[i];
    }
    while(q--)
    {
        cin>>t;
        if(t<=max && t>=min)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

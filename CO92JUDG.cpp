#include <iostream>

using namespace std;

int main()
{
    int t,n,a[100],b[100],sum1,sum2,max1,max2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum1=sum2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum1+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            sum2+=b[i];
        }
        max1=a[0]; max2=b[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>max1)
                max1=a[i];
            if(b[i]>max2)
                max2=b[i];
        }
        sum1-=max1;
        sum2-=max2;
        if(sum1<sum2)
            cout<<"Alice"<<endl;
        else if(sum1>sum2)
            cout<<"Bob"<<endl;
        else
            cout<<"Draw"<<endl;
    }
    return 0;
}

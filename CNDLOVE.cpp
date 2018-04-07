#include <iostream>

using namespace std;

int main()
{
    int t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        if(sum%2==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}


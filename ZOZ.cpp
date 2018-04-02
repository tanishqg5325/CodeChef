#include <iostream>

using namespace std;

int main()
{
    int t,n,k,sum,count;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ar[n];
        sum=count=0;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        sum-=k;
        for(int i=0;i<n;i++)
           if(ar[i]*2>sum)
                count++;
        cout<<count<<endl;
    }
    return 0;
}

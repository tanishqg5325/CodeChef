#include <iostream>

using namespace std;

int main()
{
    int t,n;
    long long count1,count2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        count1=1;
        count2=1;
        for(int i=1;i<n;i++)
        {
            if(ar[i]>=ar[i-1])
                count2++;
            else
                count2=1;
            count1+=count2;
        }
        cout<<count1<<endl;
    }
    return 0;
}

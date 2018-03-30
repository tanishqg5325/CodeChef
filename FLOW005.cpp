#include <iostream>

using namespace std;

int main()
{
    int t,n,ans,ar[6]={1,2,5,10,50,100};
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=5;i>=0;i--)
        {
            ans+=(n/ar[i]);
            n%=ar[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int t,n,ans,flag=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = n%10;
        flag=0;
        while(n)
        {
            flag=n%10;
            n/=10;
        }
        cout<<ans+flag<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=k;i++)
            if(n%i>ans)
                ans=n%i;
        cout<<ans<<endl;
    }
    return 0;
}

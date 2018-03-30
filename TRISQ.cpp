#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t,b,ans;
    cin>>t;
    while(t--)
    {
        cin>>b;
        ans=0;
        for(int i=4;i<=b;i+=2)
            ans+=floor(i/2-1);
        cout<<max(ans,0)<<endl;
    }
    return 0;
}


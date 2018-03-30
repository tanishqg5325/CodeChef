#include <iostream>

using namespace std;


int main()
{
    int t,p,ans;
    cin>>t;
    while(t--)
    {
        cin>>p;
        ans = p/2048;
        p%=2048;
        while(p)
        {
            if (p%2 == 1)
                ans++;
            p/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

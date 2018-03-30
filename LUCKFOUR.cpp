#include <iostream>

using namespace std;

int main()
{
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        while(n)
        {
            if (n%10 == 4)
                ans++;
            n/=10;
        }
        cout<<ans<<endl;
    }
    return 0;
}

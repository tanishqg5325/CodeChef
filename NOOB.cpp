#include <iostream>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    bool temp[20000]{};
    for(int i=0;i<n;i++)
    {
        if(temp[ar[i]] == 0)
        {
            ans++;
            temp[ar[i]] = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

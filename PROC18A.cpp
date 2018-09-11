#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,temp,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        temp=0;
        for(int i=0;i<k;i++) temp+=ar[i];
        ans = temp;
        for(int i=k;i<n;i++)
        {
            temp += ar[i]; temp -= ar[i-k];
            ans = max(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

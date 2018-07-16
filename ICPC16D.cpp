#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

ll a = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n],j,maxi=0; ll ans=0;
        for(int i=0;i<n;i++){ cin>>ar[i]; maxi=max(maxi,ar[i]);}
        ll cache[maxi+1]{};
        sort(ar,ar+n);
        for(int i=0;i<n;i++) cache[ar[i]]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=2*ar[i];j<=maxi;j+=ar[i])
                if(cache[j])
                    cache[j]=(cache[j]+cache[ar[i]])%a;
            ans=(ans+cache[ar[i]])%a;
        }
        cout<<ans<<endl;
    }
    return 0;
}

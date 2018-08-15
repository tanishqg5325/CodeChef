#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll S[1000001]{};
    for(int i=2;i<=1000000;i++)
    {
        if(S[i]) continue;
        for(int j=i;j<=1000000;j+=i) S[j]+=i;
    }
    int t,n; ll ans,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n]; ans=0; temp=0;
        for(int i=0;i<n;i++) cin>>ar[i];
        sort(ar,ar+n); int distinct[n];
        distinct[0] = ar[0]; int k=1;
        for(int i=1;i<n;i++)
            if(ar[i]!=ar[i-1])
                distinct[k++] = ar[i];
        int dp[ar[n-1]+1]{};
        for(int i=0;i<n;i++) dp[ar[i]]++;
        for(int i=0;i<k;i++)
        {
            temp += (dp[distinct[i]]-1);
            for(int j=2*distinct[i];j<=ar[n-1];j+=distinct[i])
                if(dp[j] && S[j]%S[distinct[i]]==0) temp+=dp[j];
            ans = ans + (temp*dp[distinct[i]]);
            temp = 0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

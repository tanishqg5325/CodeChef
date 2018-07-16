#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
using namespace std;

ll a = 1000000007;

ll power(int x, ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll tmp = power(x,n/2);
        tmp = (tmp*tmp)%a;
        return tmp;
    }
    ll tmp = power(x,(n-1)/2);
    tmp = (tmp*tmp)%a;
    tmp = (tmp*x)%a;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        sort(ar,ar+n);
        ll dp[n][k];

        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=1;i<k;i++) dp[i][i]=1;
        for(int i=2;i<n;i++)
            for(int j=1;j<min(k,i);j++)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%(a-1);

        ll ans=1,powe;
        for(int i=1;i<n-1;i++)
        {
            powe = dp[n-1][k-1];
            if(i<=n-k) powe += (a-1-dp[n-i-1][k-1]);
            if(i>=k-1) powe += (a-1-dp[i][k-1]);
            powe %= (a-1);
            ans = (ans*power(ar[i],powe))%a;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

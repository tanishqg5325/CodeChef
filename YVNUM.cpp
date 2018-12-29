#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define MAX_N 100001
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n; string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        n = str.size();
        ll pre[n+1],post[n];
        pre[0] = 0;
        for(int i=1;i<=n;i++)
            pre[i] = (pre[i-1] * 10 + str[i-1] - '0') % mod;
        post[n-1] = str[n-1] - '0';
        ll ten[n+1]; ten[0] = 1;
        for(int i=1;i<=n;i++) ten[i] = (ten[i-1] * 10) % mod;
        for(int i=n-2;i>=0;i--)
            post[i] = (post[i+1] + ten[n-1-i] * (str[i] - '0')) % mod;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ((ans * ten[n-i]) % mod + post[i]) % mod;
            ans = ((ans * ten[i]) % mod + pre[i]) % mod;
        }
        cout<<ans<<"\n";
    }
	return 0;
}


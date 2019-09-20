#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
int n,s,k; int c[101], v[101];
ll ans1;

ll power(ll n, int p) {
    ll ans = 1;
    while(p) {
        if(p & 1) ans = (ans * n) % mod;
        p = p >> 1; n = (n * n) % mod;
    }
    return ans;
}

void subset_gen(int i, vector<int> &subset)
{
    if(i == n+1) {
        int a = 0; ll va = 0;
        for(int j : subset) {a += c[j]; va = (va + v[j]) % mod;}
        if(a > s) return;
        ans1 = (ans1 + power(va, k)) % mod;
    }
    else {
        subset_gen(i+1, subset);
        subset.push_back(i);
        subset_gen(i+1, subset);
        subset.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>s>>k;
    for(int i=1;i<=n;i++) cin>>c[i]>>v[i];

    if( k <= 100) {

        ll ncr[k+1][k+1]; for(int i=0;i<=k;i++) ncr[i][0] = ncr[i][i] = 1;
        for(int i=2;i<=k;i++) for(int j=1;j<i;j++) ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;

        vector<ll> dp[n+1][s+1];
        for(int i=0;i<=n;i++) for(int j=0;j<=s;j++) dp[i][j].resize(k+1);
        for(int i=0;i<=n;i++) dp[i][0][k] = 1;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=s;j++) {
                dp[i][j] = dp[i-1][j];
                if(j < c[i]) continue;
                vector<ll> &tmp = dp[i-1][j-c[i]];
                for(int l=0;l<=k;l++) {
                    ll a = 1;
                    for(int m=l;m<=k;m++) {
                        dp[i][j][l] = (dp[i][j][l] + ((ncr[k-l][m-l] * tmp[m]) % mod * a) % mod) % mod;
                        a = (a * v[i]) % mod; 
                    }
                }
            }
        ll ans = 0;
        for(int i=1;i<=s;i++) ans = (ans + dp[n][i][0]) % mod;
        cout<<ans<<"\n";
        return 0;
    }

    vector<int> subset;
    subset_gen(1, subset);
    cout<<ans1<<"\n";

    return 0;
}

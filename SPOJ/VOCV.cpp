#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100011
using namespace std;

int dp[MAXN][2], dp2[MAXN][2];
vector<int> adj[MAXN];
int mod = 10007;

void dfs(int u, int par)
{
    int taking_u = 1, not_taking_u = 0, ways_taking_u = 1, ways_not_taking_u = 1;
    for(int v : adj[u])
    {
        if(v == par) continue;
        dfs(v, u);
        taking_u += dp[v][1];
        not_taking_u += dp[v][0];
        ways_taking_u = (ways_taking_u * dp2[v][1]) % mod;
        ways_not_taking_u = (ways_not_taking_u * dp2[v][0]) % mod;
    }
    dp[u][1] = min(not_taking_u, taking_u);
    dp[u][0] = taking_u;
    dp2[u][0] = ways_taking_u;
    if(not_taking_u > taking_u) dp2[u][1] = ways_taking_u;
    else if(not_taking_u < taking_u) dp2[u][1] = ways_not_taking_u;
    else dp2[u][1] = (ways_taking_u + ways_not_taking_u) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,u,v; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 0);
        cout<<dp[1][1]<<" "<<dp2[1][1]<<"\n";
    }
    return 0;
}

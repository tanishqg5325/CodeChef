#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int dp[100001][2];
vector<int> adj[100001];

void dfs(int u, int par)
{
    int taking_u = 1, not_taking_u = 0;
    for(int v : adj[u])
    {
        if(v == par) continue;
        dfs(v, u);
        taking_u += dp[v][1];
        not_taking_u += dp[v][0];
    }
    dp[u][1] = min(not_taking_u, taking_u);
    dp[u][0] = taking_u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,u,v; cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    cout<<min(dp[1][0], dp[1][1])<<"\n";
    return 0;
}

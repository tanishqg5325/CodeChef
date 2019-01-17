#include <bits/stdc++.h>
#define pb push_back
#define MAXN 10001
using namespace std;

bool color[MAXN],isImbal[MAXN];
set<int> adj[MAXN];

void dfs1(int u, int par, bool c)
{
    color[u] = c;
    for(int i : adj[u]) if(i != par) dfs1(i, u, c^1);
}

void dfs2(int u, int par)
{
    vector<int> v; int k,i,j;
    for(int i : adj[u])
    {
        if(i == par) continue;
        dfs2(i, u);
        if(isImbal[i]) v.pb(i);
    }
    k = v.size();
    if(k & 1) isImbal[u] = 0; else isImbal[u] = 1;
    while(k >= 2)
    {
        i = v[k-1]; j = v[k-2]; k -= 2;
        adj[u].erase(i); adj[i].erase(u);
        adj[j].insert(i); adj[i].insert(j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,u,v; cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {cin>>u>>v; adj[u].insert(v); adj[v].insert(u);}
        dfs1(1,0,0); u = v = 0;
        for(int i=1;i<=n;i++) {if(color[i]) v++; else u++;}
        if(v == u) cout<<"1\n";
        else {cout<<"2\n"; dfs2(1,0); dfs1(1,0,0);}
        for(int i=1;i<=n;i++) if(!color[i]) cout<<i<<" "; cout<<"\n";
        for(int i=1;i<=n;i++) if(color[i]) cout<<i<<" "; cout<<"\n";
    }
    return 0;
}

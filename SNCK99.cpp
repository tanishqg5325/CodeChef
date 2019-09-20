#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[513];

void remov(int e)
{
    cout<<e<<endl;
    int k,a,b; cin>>k;
    if(k < 2) cin>>a>>b;
}

void dfs(int u, int color[], int curr, bool active[])
{
    color[u] = curr;
    for(pii i : adj[u])
    {
        if(active[i.Y]) continue;
        if(color[i.X] == 0) dfs(i.X, color, 3-curr, active);
        else if(color[i.X] == curr) {active[i.Y] = 1; remov(i.Y);}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,a,u,v; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a;
    for(int i=0;i<m;i++) cin>>a;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    int color[n+1]{}; bool active[m+1]{};
    dfs(n, color, 1, active);
    cout<<"-1"<<endl;
    for(int i=1;i<=n;i++)
    {
        if(color[i] == 1) cout<<"C";
        else cout<<"G";
    }
    cout<<endl;
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define N 10000
#define LN 14
using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[N];
int dist[N], depth[N], pa[LN][N];

int LCA(int u, int v)
{
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<LN;i++) if((diff>>i) & 1) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1;i>=0;i--)
        if(pa[i][u] != pa[i][v])
        {
            u = pa[i][u];
            v = pa[i][v];
        }
	return pa[0][u];
}

int query(int curr, int k)
{
    for(int i=0;i<LN;i++) if((k>>i) & 1) curr = pa[i][curr];
    return curr + 1;
}

void dfs(int curr, int par, int _depth, int _dist)
{
    pa[0][curr] = par; depth[curr] = _depth; dist[curr] = _dist;
    for(pii i : adj[curr])
        if(i.X != par)
            dfs(i.X, curr, _depth + 1, _dist + i.Y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,u,v,c,a,b,lca,k; string str; cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            for(int j=0; j<LN; j++) pa[j][i] = -1;
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>c; u--; v--;
            adj[u].pb({v, c}); adj[v].pb({u, c});
        }
        dfs(0, -1, 0, 0);
        for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
        cin>>str;
        while(str[1] != 'O')
        {
			cin>>a>>b; a--; b--; lca = LCA(a, b);
			if(str[1] == 'I') cout<<dist[a] + dist[b] - 2*dist[lca]<<"\n";
            else
            {
                cin>>k;
                if(depth[a] - depth[lca] + 1 >= k) cout<<query(a, k - 1)<<"\n";
                else cout<<query(b, depth[a] + depth[b] - 2*depth[lca] - k + 1)<<"\n";
            }
            cin>>str;
		}
    }
    return 0;
}

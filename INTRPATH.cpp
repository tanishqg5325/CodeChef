#include <bits/stdc++.h>
#define pb push_back
#define N 300000
#define LN 19
using namespace std;
typedef long long ll;

vector<int> adj[N];
int pa[LN][N], depth[N];
ll subsize[N], subsize_sq[N], weights[N], cum_weights[N];

int LCA(int u, int v)
{
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<LN;i++) if((diff>>i)&1) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1;i>=0;i--)
        if(pa[i][u] != pa[i][v])
        {
            u = pa[i][u];
            v = pa[i][v];
        }
	return pa[0][u];
}

int findu(int u, int h)
{
    for(int i=0;i<LN;i++) if((h>>i)&1) u = pa[i][u];
    return u;
}

inline ll sq(ll a) {return a*a;}

void dfs1(int u, int par, int _depth=0)
{
    pa[0][u] = par; depth[u] = _depth; subsize[u] = 1; subsize_sq[u] = 0;
    for(int i : adj[u])
        if(i != par)
        {
            dfs1(i, u, _depth+1);
            subsize[u] += subsize[i];
            subsize_sq[u] += sq(subsize[i]);
        }
}

void dfs2(int u, int par)
{
    for(int i: adj[u])
        if(i != par)
        {
            cum_weights[i] = cum_weights[u] + weights[i];
            dfs2(i, u);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,q,u,v,par,lca,tmp; ll ans; cin>>T;
    while(T--)
    {
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            for(int j=0;j<LN;j++) pa[j][i] = -1;
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v; u--; v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        dfs1(0, -1);
        for(int i=1;i<LN;i++)
			for(int j=0;j<n;j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
        for(int i=1;i<n;i++)
        {
            par = pa[0][i];
            weights[i] = subsize[par] - subsize[i] + (sq(subsize[par] - subsize[i] - 1) - subsize_sq[par] + sq(subsize[i])) / 2;
        }
        cum_weights[0] = 0; dfs2(0, -1);
        while(q--)
        {
            cin>>u>>v; u--; v--;
            if(u == v)
            {
                ans = n + (sq(subsize[u] - 1) - subsize_sq[u])/2 + (subsize[u] - 1) * (n - subsize[u]);
                cout<<ans<<"\n"; continue;
            }
            lca = LCA(u, v); if(lca == v) swap(u, v);
            if(lca == u)
            {
                ans = subsize[v] + (sq(subsize[v] - 1) - subsize_sq[v])/2;
                ans += (cum_weights[v] - cum_weights[u]);
                tmp = findu(v, depth[v] - depth[u] - 1);
                ans += (n - subsize[u]) * (subsize[u] - subsize[tmp]);
                cout<<ans<<"\n"; continue;
            }
            ans = subsize[v] + (sq(subsize[v] - 1) - subsize_sq[v])/2;
            ans += (subsize[u] + (sq(subsize[u] - 1) - subsize_sq[u])/2);
            int t1 = findu(u, depth[u] - depth[lca] - 1), t2 = findu(v, depth[v] - depth[lca] - 1);
            ans += (cum_weights[u] + cum_weights[v] - cum_weights[t1] - cum_weights[t2]);
            ans += (n - subsize[t1] - subsize[t2]);
            ans += (sq(subsize[lca] - subsize[t1] - subsize[t2] - 1) - subsize_sq[lca] + sq(subsize[t1]) + sq(subsize[t2])) / 2;
            ans += (n - subsize[lca]) * (subsize[lca] - subsize[t1] - subsize[t2] - 1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define LN 20
#define N 1000001
using namespace std;

int pa[LN][N];

void dfs(int u, int par, int ar[], vector<int> adj[], vector<int> adj1[])
{
    if(u != 1) pa[0][u] = par;
    if(ar[u] > ar[par])
    {
        adj1[par].pb(u);
        for(int i : adj[u])
            dfs(i, u, ar, adj, adj1);
    }
    else
    {
        for(int i : adj[u])
            dfs(i, par, ar, adj, adj1);
    }
}

int findu(int v, int w, int ar[])
{
    int ans = 1;
    for(int i=LN-1;i>=0;i--)
    {
        if(pa[i][v] == -1 || ar[pa[i][v]] <= w) continue;
        v = pa[i][v];
        ans += (1<<i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,p,q,a,b,v,w,ans; cin>>T;
    while(T--)
    {
        cin>>n; int ar[n+1]; ar[0] = 0;
        for(int i=1;i<=n;i++) cin>>ar[i];
        vector<int> adj[n+1];
        for(int i=2;i<=n;i++)
        {
            cin>>p;
            adj[p].pb(i);
        }
        vector<int> adj1[n+1];
        for(int i=1;i<=n;i++) for(int j=0;j<LN;j++) pa[j][i] = -1;
        dfs(1, 0, ar, adj, adj1);
        for(int i=1;i<LN;i++)
			for(int j=1;j<=n;j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
        cin>>q; ans = 0;
        while(q--)
        {
            cin>>a>>b;
            v = a ^ ans; w = b ^ ans;
            if(v == 1)
            {
                if(ar[1] > w) ans = 1;
                else ans = 0;
                cout<<ans<<"\n";
                continue;
            }
            p = pa[0][v];
            if(ar[p] <= w)
            {
                if(ar[v] > w) ans = 1;
                else ans = 0;
                cout<<ans<<"\n";
                continue;
            }
            if(ar[v] > ar[p]) ans = findu(v, w, ar);
            else ans = findu(p, w, ar);
            cout<<ans<<"\n";
        }
    }
    return 0;
}

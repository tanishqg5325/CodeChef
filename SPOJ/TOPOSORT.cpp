#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,u,v;
    cin>>n>>m; int indeg[n+1]{};
    vector<int> adj[n+1];
    while(m--)
    {
        cin>>u>>v; indeg[v]++;
        adj[u].pb(v);
    }
    set<int> topo;
    for(int i=1;i<=n;i++) if(indeg[i] == 0) topo.insert(i);
    vector<int> ans;
    while(!topo.empty())
    {
        u = *(topo.begin());
        ans.pb(u);
        topo.erase(topo.begin());
        for(auto i : adj[u])
        {
            indeg[i]--;
            if(indeg[i] == 0) topo.insert(i);
        }
    }
    int sz = ans.size();
    if(sz != n) cout<<"Sandro fails.\n";
    else
    {
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
	return 0;
}

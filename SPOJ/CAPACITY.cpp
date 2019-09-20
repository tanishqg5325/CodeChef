#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;

void dfs1(vector<int> g[], stack<int> &s, bool visited[], int u)
{
    visited[u] = 1;
    for(int i : g[u])
        if(!visited[i])
            dfs1(g, s, visited, i);
    s.push(u);
}

void dfs2(int u, vector<int> g[], bool visited[], int counter, int scc[], vector<int> adj[])
{
    visited[u] = 0; scc[u] = counter;
    for(int i : g[u])
    {
        if(visited[i]) dfs2(i, g, visited, counter, scc, adj);
        else if(scc[i] != counter) adj[counter].pb(scc[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,a,b; cin>>n>>m;
    vector<int> out[n+1],in[n+1];
    while(m--)
    {
        cin>>a>>b;
        out[a].pb(b); in[b].pb(a);
    }
    stack<int> s; bool visited[n+1]{};
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs1(in, s, visited, i);
    int scc[n+1], counter = 1,k;
    vector<int> adj[n+1];
    while(!s.empty())
    {
        k = s.top(); s.pop();
        if(visited[k])
        {
            dfs2(k, out, visited, counter, scc, adj);
            counter++;
        }
    }
    a = 0;
    for(int i=1;i<counter;i++) if(adj[i].empty()) {a++; b = i;}
    assert(a >= 1);
    if(a > 1) cout<<"0\n";
    else
    {
        vector<int> ans;
        for(int i=1;i<=n;i++) if(scc[i] == b) ans.pb(i);
        cout<<ans.size()<<"\n";
        for(int i : ans) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

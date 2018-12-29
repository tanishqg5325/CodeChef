#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;

class Graph
{
    int V;
    pii *deg;
    int *indeg;
public:
    set<pii> *adj;

    Graph(int v)
    {
        V = v;
        adj = new set<pii>[v];
        deg = new pii[v];
        indeg = new int[v];
        for(int i=0;i<v;i++) {deg[i] = mp(0,i); indeg[i] = 0;}
    }

    void addEdge(int u, int v)
    {
        adj[u].insert(mp(v,1)); deg[u].first++;
        adj[v].insert(mp(u,1)); deg[v].first++;
    }

    void solve()
    {
        set<pii> undeg(deg, deg + V);
        while(!undeg.empty())
        {
            pii set_v = *(undeg.begin());
            undeg.erase(undeg.begin());
            int u = set_v.second, k=-1, i; bool first = 0;
            if(indeg[u] & 1) first = 1;
            for(set<pii>::iterator j = adj[u].begin(); j != adj[u].end(); j++)
            {
                i = (*j).first;
                if((*j).second == 0 || adj[i].find(mp(u,1)) == adj[i].end()) continue;
                if(first) {indeg[u]++; k = i; first = 0;}
                else {adj[i].erase(adj[i].find(mp(u,1))); adj[i].insert(mp(u,0)); indeg[i]++;}
                undeg.erase(undeg.find(deg[i])); deg[i].first--;
                if(deg[i].first) undeg.insert(deg[i]);
            }
            if(k != -1) {adj[u].erase(adj[u].find(mp(k,1))); adj[u].insert(mp(k,0));}
        }
        vector<int> v;
        for(int i=0;i<V;i++) if(indeg[i] & 1) v.pb(i);
        if(v.size() == 0) return;
        bool visited[V];
        for(int i=0;i<v.size();i++)
        {
            if(indeg[v[i]] % 2 == 0) continue;
            memset(visited, 0, sizeof(visited));
            dfs(v[i],v[i],visited);
        }
    }

    bool dfs(int start, int u, bool visited[])
    {
        visited[u] = 1;
        if(u != start && (indeg[u] & 1)) {indeg[u]++; return true;}
        int v;
        for(set<pii>::iterator i = adj[u].begin(); i != adj[u].end(); i++)
        {
            v = (*i).first;
            if(visited[v]) continue;
            if(!dfs(start,v,visited)) continue;
            if((*i).second) {int t = u; u = v; v = t;}
            adj[u].erase(adj[u].find(mp(v,0)));
            adj[u].insert(mp(v,1));
            adj[v].erase(adj[v].find(mp(u,1)));
            adj[v].insert(mp(u,0));
            return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        Graph g(n); int u[m],v[m];
        for(int i=0;i<m;i++) {cin>>u[i]>>v[i]; u[i]--; v[i]--; g.addEdge(u[i],v[i]);}
        if(m & 1) {cout<<"-1\n"; continue;}
        g.solve();
        for(int i=0;i<m;i++)
        {
            if(g.adj[u[i]].find(mp(v[i],1)) == g.adj[u[i]].end()) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}

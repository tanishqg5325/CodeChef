#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf INT_MAX
using namespace std;

vector<pii> back_v[505];

class Graph
{
    int V;
    set<pii> *adj;

public:
    Graph(int v)
    {
        V = v;
        adj = new set<pii>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].insert(mp(v,w));
    }

    void removeEdge(int u, int v, int w)
    {
        if(adj[u].find(mp(v,w)) == adj[u].end()) return;
        adj[u].erase(adj[u].find(mp(v,w)));
    }

    int dijkstra(int src, int dest)
    {
        vector<int> dist(V, inf); dist[src] = 0;
        set<pii> temp_dist; temp_dist.insert(mp(0,src));
        while(!temp_dist.empty())
        {
            pii set_v = *(temp_dist.begin());
            temp_dist.erase(temp_dist.begin());
            int u = set_v.second;
            for(set<pii>::iterator i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = (*i).first;
                int w = (*i).second;
                if(dist[v] > dist[u] + w)
                {
                    if(dist[v] != inf)
                        temp_dist.erase(temp_dist.find(mp(dist[v],v)));
                    back_v[v].clear();
                    dist[v] = dist[u] + w;
                    temp_dist.insert(mp(dist[v], v));
                    back_v[v].pb(mp(u,w));
                }
                else if(dist[v] == dist[u] + w)
                    back_v[v].pb(mp(u,w));
            }
        }
        return dist[dest];
    }
};

void removeShortest(int v, Graph &g)
{
    if(back_v[v].empty()) return;
    for(vector<pii>::iterator i = back_v[v].begin(); i != back_v[v].end(); i++)
    {
        int u = (*i).first, w = (*i).second;
        g.removeEdge(u,v,w);
        removeShortest(u, g);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,s,d,u,v,w,ans;
    cin>>n>>m;
    while(n || m)
    {
        Graph g(n);
        cin>>s>>d;
        while(m--)
        {
            cin>>u>>v>>w;
            g.addEdge(u,v,w);
        }
        g.dijkstra(s, d);
        removeShortest(d, g);
        ans = g.dijkstra(s, d);
        if(ans == inf) cout<<"-1\n";
        else cout<<ans<<"\n";
        for (auto& v : back_v) v.clear();
        cin>>n>>m;
    }
    return 0;
}

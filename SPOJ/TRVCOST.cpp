#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf INT_MAX
using namespace std;

class Graph
{
    int V;
    vector<pii> *adj;

public:
    Graph(int v)
    {
        V = v;
        adj = new vector<pii>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }

    vector<int> dijkstra(int src)
    {
        vector<int> dist(V, inf); dist[src] = 0;
        set<pii> temp_dist; temp_dist.insert(mp(0,src));
        while(!temp_dist.empty())
        {
            pii set_v = *(temp_dist.begin());
            temp_dist.erase(temp_dist.begin());
            int u = set_v.second;
            for(vector<pii>::iterator i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = (*i).first;
                int w = (*i).second;
                if(dist[v] > dist[u] + w)
                {
                    if(dist[v] != inf)
                        temp_dist.erase(temp_dist.find(mp(dist[v], v)));
                    dist[v] = dist[u] + w;
                    temp_dist.insert(mp(dist[v], v));
                }
            }
        }
        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n = 501,m,u,v,w,q;
    Graph g(n);
    cin>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cin>>u;
    vector<int> dist = g.dijkstra(u);
    cin>>q;
    while(q--)
    {
        cin>>v;
        if(dist[v] == inf) cout<<"NO PATH\n";
        else cout<<dist[v]<<"\n";
    }
    return 0;
}

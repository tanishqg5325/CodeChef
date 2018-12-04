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

struct edge
{
    int u,v,w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,k,s,t,u,v,w;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>s>>t; s--; t--;
        Graph g1(n),g2(n); edge new_roads[k];
        while(m--)
        {
            cin>>u>>v>>w; u--; v--;
            g1.addEdge(u,v,w);
            g2.addEdge(v,u,w);
        }
        for(int i=0;i<k;i++)
        {
            cin>>new_roads[i].u>>new_roads[i].v>>new_roads[i].w;
            new_roads[i].u--; new_roads[i].v--;
        }
        vector<int> d1 = g1.dijkstra(s);
        vector<int> d2 = g2.dijkstra(t);
        int ans = d1[t];
        for(int i=0;i<k;i++)
        {
            u = new_roads[i].u; v = new_roads[i].v; w =new_roads[i].w;
            if(d1[u] != inf && d2[v] != inf)
                ans = min(ans, d1[u] + w + d2[v]);
            if(d1[v] != inf && d2[u] != inf)
                ans = min(ans, d1[v] + w + d2[u]);
        }
        if(ans == inf) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}

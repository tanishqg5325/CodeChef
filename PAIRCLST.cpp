#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf INT_MAX
using namespace std;

bool isSpecial[100005]{};

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

    int dijkstra(int src, int ans)
    {
        vector<int> dist(V, inf); dist[src] = 0;
        set<pii> temp_dist; temp_dist.insert(mp(0,src));
        while(!temp_dist.empty())
        {
            pii set_v = *(temp_dist.begin());
            temp_dist.erase(temp_dist.begin());
            int u = set_v.second;
            if((u != src && isSpecial[u]) || dist[u] >= ans) return dist[u];
            if(dist[u] >= ans) return inf;
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
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,k,u,v,w,q;
    cin>>n>>m>>k;
    int sp[k];
    for(int i=0;i<k;i++)
    {
        cin>>sp[i]; sp[i]--;
        isSpecial[sp[i]] = 1;
    }
    Graph g(n);
    while(m--)
    {
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }
    int ans = inf;
    for(int i=0;i<k;i++)
        ans = min(ans, g.dijkstra(sp[i], ans));
    cout<<ans<<"\n";
    return 0;
}

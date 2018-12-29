#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<ll,int>
#define inf LLONG_MAX
typedef long long ll;
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

    ll dijkstra(int src, int dest)
    {
        vector<ll> dist(V, inf); dist[src] = 0;
        set<pli> temp_dist; temp_dist.insert(mp(dist[src],src));
        while(!temp_dist.empty())
        {
            pli set_v = *(temp_dist.begin());
            temp_dist.erase(temp_dist.begin());
            int u = set_v.second;
            if(u == dest) break;
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
        return dist[dest];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,r,u,v,src=0;
    cin>>n>>r;
    Graph g(2*n + 2); int h[n],c[n];
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>c[i];
    while(r--)
    {
        cin>>u>>v; u--; v--;
        if(h[u] <= h[v]) {g.addEdge(u,v,0); g.addEdge(v+n,u+n,0);}
        if(h[v] <= h[u]) {g.addEdge(u+n,v+n,0); g.addEdge(v,u,0);}
    }
    for(int i=0;i<n;i++)
    {
        g.addEdge(i,i+n,c[i]);
        g.addEdge(i+n,i,c[i]);
    }
    g.addEdge(2*n, 0, c[0]); g.addEdge(2*n, n, c[0]);
    g.addEdge(n-1, 2*n+1, 0); g.addEdge(2*n-1, 2*n+1, 0);
    ll ans = g.dijkstra(2*n, 2*n+1);
    if(ans == inf) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}

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

    int dijkstra(int src, int dest)
    {
        vector<int> dist(V, inf); dist[src] = 0;
        set<pii> temp_dist; temp_dist.insert(mp(0,src));
        while(!temp_dist.empty())
        {
            pii set_v = *(temp_dist.begin());
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
    int t,n,r,v,w,q; string str,str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>n; unordered_map<string,int> cities;
        Graph g(n);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            cities[str] = i;
            cin>>r;
            while(r--)
            {
                cin>>v>>w;
                g.addEdge(i,v-1,w);
            }
        }
        cin>>q;
        while(q--)
        {
            cin>>str1>>str2;
            cout<<g.dijkstra(cities[str1], cities[str2])<<"\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
public:
    Graph(int v)
    {
        V = v;
        adj = new vector<int>[v];
    }

    void addEdge(int s, int d)
    {
        adj[s].pb(d);
        adj[d].pb(s);
    }

    void dfs(int v, bool *visited)
    {
        visited[v] = 1;
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++)
            if(!visited[*i])
                dfs(*i, visited);
    }

    bool solve()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        dfs(0, visited);
        for(int i=0;i<V;i++)
            if(!visited[i])
                return 0;
        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,x,y;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g.addEdge(x-1, y-1);
    }
    if(m == n-1 && g.solve()) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}


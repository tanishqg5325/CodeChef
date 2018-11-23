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
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
            if(!visited[*i])
                dfs(*i, visited);
    }

    int solve()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        int ans = 0;
        for(int i=0;i<V;i++)
            if(!visited[i])
            {
                dfs(i, visited);
                ans++;
            }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        Graph g(n);
        while(m--)
        {
            cin>>i>>j;
            g.addEdge(i, j);
        }
        cout<<g.solve()<<"\n";
    }
    return 0;
}


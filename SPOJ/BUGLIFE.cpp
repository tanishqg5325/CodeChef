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

    bool dfs(int v, int *visited, int color)
    {
        visited[v] = color;
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
            {
                if(!dfs(*i, visited, (color == 1)?2:1))
                    return false;
            }
            else if(visited[*i] == color)
                return false;
        }
        return true;
    }

    bool solve()
    {
        int *visited = new int[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(!dfs(i, visited, 1))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,i,j;
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n>>m;
        Graph g(n);
        while(m--)
        {
            cin>>i>>j;
            g.addEdge(i-1, j-1);
        }
        cout<<"Scenario #"<<T<<":\n";
        if(g.solve()) cout<<"No suspicious bugs found!\n";
        else cout<<"Suspicious bugs found!\n";
    }
    return 0;
}

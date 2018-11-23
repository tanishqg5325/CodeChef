#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ll mod = 1000000007;

class Graph
{
    int V;
    ll *ways;
    vector<int> *adj;

public:
    Graph(int v)
    {
        V = v;
        adj = new vector<int>[V];
        ways = new ll[V];
        for(int i=0;i<V;i++) ways[i] = -1;
    }

    void addEdge(int s, int d)
    {
        adj[s].pb(d);
        adj[d].pb(d);
    }

    ll dfs(int v, bool *visited, int end)
    {
        if(ways[v] == -1)
        {
            visited[v] = 1; ways[v] = 0;
            vector<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); i++)
            {
                if(!visited[*i])
                    ways[v] = (ways[v] + dfs(*i, visited, end)) % mod;
            }
            visited[v] = 0;
        }
        return ways[v];
    }

    ll solve(int start, int end)
    {
        ways[end] = 1;
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        return dfs(start, visited, end);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,i,j,s,t;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>s>>t;
        Graph g(n);
        while(m--)
        {
            cin>>i>>j;
            g.addEdge(i-1, j-1);
        }
        cout<<g.solve(s-1, t-1)<<"\n";
    }
    return 0;
}

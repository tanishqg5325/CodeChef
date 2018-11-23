#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ll mod = 1000000007;

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

    int dfs(int v, bool *visited)
    {
        visited[v] = 1; int ans = 1;
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
                ans += dfs(*i, visited);
        }
        return ans;
    }

    void solve()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        int compo = 0; ll capt = 1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                compo++;
                capt = (capt * dfs(i, visited)) % mod;
            }
        }
        cout<<compo<<" "<<capt<<"\n";
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
            g.addEdge(i-1, j-1);
        }
        g.solve();
    }
    return 0;
}

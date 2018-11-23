#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int x;

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

    void dfs(int v, int count, int &maxcount, bool *visited)
    {
        count++;
        visited[v] = true;
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
            {
                if(count > maxcount)
                    maxcount = count, x = *i;
                dfs(*i, count, maxcount, visited);
            }
        }
    }

    int solve()
    {
        int maxcount = 0;
        bool *visited = new bool[V];
        for(int i=0;i<V;i++) visited[i] = false;
        dfs(0, 0, maxcount, visited);
        for(int i=0;i<V;i++) visited[i] = false;
        dfs(x, 0, maxcount, visited);
        return maxcount;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,i,j;
    cin>>n; m = n-1;
    Graph g(n);
    while(m--)
    {
        cin>>i>>j;
        g.addEdge(i-1, j-1);
    }
    cout<<g.solve()<<"\n";
    return 0;
}

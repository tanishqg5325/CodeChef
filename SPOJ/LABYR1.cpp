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
            if(!visited[*i])
            {
                if(count > maxcount)
                    maxcount = count, x = *i;
                dfs(*i, count, maxcount, visited);
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
    int t,n,m,i,j; char c;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        int ar[n][m],k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>c;
                if(c == '#') ar[i][j] = -1;
                else ar[i][j] = k++;
            }
        }
        Graph g(k);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(ar[i][j] == -1) continue;
                if(i+1 < n && ar[i+1][j] != -1) g.addEdge(ar[i][j], ar[i+1][j]);
                if(j+1 < m && ar[i][j+1] != -1) g.addEdge(ar[i][j], ar[i][j+1]);
            }
        cout<<"Maximum rope length is "<<g.solve()<<".\n";
    }
    return 0;
}

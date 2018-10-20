#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isConnected();
};

bool Graph::isConnected()
{
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++) visited[v] = false;
    DFSUtil(0,visited);
    for (int v=1; v<V; v++) if (visited[v] == false) return 0;
    return 1;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) if(!visited[*i]) DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int gcd(int m, int n)
{
    if(n == 0) return m;
    return gcd(n,m%n);
}

void print(int b[], int n)
{
    for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,b[51]; bool flag;
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>n; Graph g(n);
        for(int i=1;i<=n;i++) {cin>>b[i]; if(b[i] == 29) flag=1;}
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(gcd(b[i],b[j]) == 1)
                    g.addEdge(i-1,j-1);
        if(g.isConnected())
        {
            cout<<"0\n"; print(b,n); continue;
        }
        if(flag) b[1] = 31; else b[1] = 29;
        cout<<"1\n"; print(b,n);
    }
    return 0;
}

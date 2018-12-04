#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    int *dist;

public:
    Graph(int v)
    {
        V = v;
        adj = new vector<int>[V];
        dist = new int[V];
    }

    void addEdge(int s, int d)
    {
        adj[s].pb(d);
    }

    void solve(int a, int b)
    {
        int *visited = new int[V];
        for(int i=0;i<V;i++) visited[i] = 0, dist[i] = -1;
        dist[a] = 0;
        queue<int> q; q.push(a); visited[a] = 1;
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            for(vector<int>::iterator i = adj[a].begin(); i != adj[a].end(); ++i)
                if(!visited[*i])
                {
                    dist[*i] = dist[a] + 1;
                    visited[*i] = 1;
                    q.push(*i);
                }
        }
        if(dist[b] == -1) cout<<"use the stairs\n";
        else cout<<dist[b]<<"\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d; s--; g--;
    Graph gh(f);
    for(int i=0;i<f;i++)
    {
        if(u!=0 && i+u < f) gh.addEdge(i,i+u);
        if(d!=0 && i-d >= 0) gh.addEdge(i,i-d);
    }
    gh.solve(s,g);
    return 0;
}

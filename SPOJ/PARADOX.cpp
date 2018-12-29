#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Graph
{
    int V;
    vector<pair<int,bool>> *adj;
public:
    Graph(int v)
    {
        V = v;
        adj = new vector<pair<int,bool>>[v];
    }

    void addEdge(int s, int d, bool b)
    {
        adj[s].pb({d,b});
        adj[d].pb({s,b});
    }

    int findColor(int color, bool weight)
    {
        color--;
        return !(color ^ weight) + 1;
    }

    bool dfs(int v, int *visited, int color)
    {
        visited[v] = color;
        for(auto i : adj[v])
        {
            if(!visited[i.first])
            {
                if(!dfs(i.first, visited, findColor(color, i.second)))
                    return false;
            }
            else if(visited[i.first] != findColor(color, i.second))
                return false;
        }
        return true;
    }

    bool solve()
    {
        int *visited = new int[V];
        for(int i=0;i<V;i++) visited[i] = 0;
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(!dfs(i, visited, 1))
                    return false;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,x; string s;
    cin>>n;
    while(n)
    {
        Graph g(n);
        for(int i=0;i<n;i++)
        {
            cin>>x>>s;
            g.addEdge(i, x-1, s.compare("false"));
        }
        if(g.solve()) cout<<"NOT PARADOX\n";
        else cout<<"PARADOX\n";
        cin>>n;
    }
    return 0;
}


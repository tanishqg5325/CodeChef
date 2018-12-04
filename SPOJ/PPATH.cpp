#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool isPrime[10000]{};

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
        adj[d].pb(s);
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
        if(dist[b] == -1) cout<<"Impossible\n";
        else cout<<dist[b]<<"\n";
    }
};

string itoa(int n)
{
    string str = "";
    str += ((n/1000) + '0'); n %= 1000;
    str += ((n/100) + '0'); n %= 100;
    str += ((n/10) + '0'); n %= 10;
    str += (n + '0');
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=2;i<10000;i++) isPrime[i] = 1;
    for(int i=2;i<10000;i++)
    {
        if(!isPrime[i]) continue;
        for(int j=2*i;j<10000;j+=i) isPrime[j] = 0;
    }
    Graph g(10000); string s; char c; int b,t,a;
    for(int i=1001;i<10000;i++)
    {
        if(!isPrime[i]) continue;
        s = itoa(i);
        for(int j=0;j<4;j++)
        {
            c = s[j];
            for(int k=0;k<10;k++)
            {
                s[j] = k + '0';
                b = stoi(s);
                if(b != i && b>=1000 && isPrime[b])
                    g.addEdge(i, b);
            }
            s[j] = c;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        g.solve(a,b);
    }
    return 0;
}

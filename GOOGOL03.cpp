#include <bits/stdc++.h>
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define X first
#define Y second
#define MAX_N 200000
typedef long long ll;
using namespace std;

vector<int> mst[MAX_N];
vector<ll> ans[MAX_N];
int n;

ll dfs(int v, bool visited[])
{
    visited[v] = 0; ll sum = 0,tmp;
    for(auto i : mst[v])
    {
        if(visited[i])
        {
            tmp = dfs(i, visited) + 1;
            ans[v].pb(tmp);
            sum += tmp;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m,u,v,w;
    cin>>n>>m;
    vector<pair<int,pii>> g[n];
    while(m--)
    {
        cin>>u>>v>>w; u--; v--;
        g[u].pb({w,{u,v}});
        g[v].pb({w,{v,u}});
    }
    bool visited[n]{}; visited[0] = 1; int count = 0;
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq(g[0].begin(), g[0].end());
    while(!pq.empty() && count < n-1)
    {
        pair<int,pii> tmp = pq.top(); pq.pop();
        if(visited[tmp.Y.Y]) continue;
        visited[tmp.Y.Y] = 1; count++;
        mst[tmp.Y.X].pb(tmp.Y.Y);
        mst[tmp.Y.Y].pb(tmp.Y.X);
        for(auto i : g[tmp.Y.Y]) if(!visited[i.Y.Y]) pq.push(i);
    }
    assert(dfs(0, visited) == n-1);
    pli busy[n]; ll sum1,sum2;
    for(int i=0;i<n;i++)
    {
        sum1 = sum2 = 0;
        for(auto j : ans[i])
        {
            sum2 += (j*j);
            sum1 += j;
        }
        sum2 += (n-1-sum1) * (n-1-sum1);
        busy[i] = {sum2, i+1};
    }
    sort(busy, busy+n);
    for(int i=0;i<n;i++) cout<<busy[i].Y<<"\n";
    return 0;
}

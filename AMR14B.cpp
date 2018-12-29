#include <bits/stdc++.h>
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define inf LLONG_MAX
typedef long long ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,u,v,w,i,src; ll wt1,wt2; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<pii> g[n];
        while(m--)
        {
            cin>>u>>v>>w;
            g[u].pb({w,v});
            g[v].pb({w,u});
        }
        bool visited[n]{}; visited[0] = 1; wt1 = wt2 = 0;
        priority_queue<pii, vector<pii>, greater<pii>>  pq(g[0].begin(), g[0].end());
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            if(visited[tmp.second]) continue;
            visited[tmp.second] = 1;
            wt1 += tmp.first;
            for(auto i : g[tmp.second]) pq.push(i);
        }
        
        for(i=0;i<n;i++) if(!visited[i]) break;
        if(i < n) {cout<<"NO\n"; continue;}
        
        vector<ll> dist(n, inf); dist[src] = 0;
        set<pli> temp_dist; temp_dist.insert({dist[src],src});
        int last_wt[n]{};
        while(!temp_dist.empty())
        {
            pli set_v = *(temp_dist.begin());
            temp_dist.erase(temp_dist.begin());
            int u = set_v.second;
            for(auto i : g[u])
            {
                w = i.first; v = i.second;
                if(dist[v] > dist[u] + w)
                {
                    if(dist[v] != inf)
                    {
                        temp_dist.erase(temp_dist.find({dist[v], v}));
                        wt2 -= last_wt[v];
                    }
                    dist[v] = dist[u] + w;
                    last_wt[v] = w; wt2 += w;
                    temp_dist.insert({dist[v], v});
                }
                else if(dist[v] == dist[u] + w)
                {
                    if(w < last_wt[v]) {wt2 -= last_wt[v]; wt2 += w; last_wt[v] = w;}
                }
            }
        }
        if(wt1 == wt2) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}


#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,u,v;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n>>m;
        vector<int> adj[n]; int indeg[n]{};
        while(m--)
        {
            cin>>u>>v; indeg[u]++;
            adj[v].pb(u);
        }
        set<pii> topo;
        cout<<"Scenario #"<<t<<":\n";
        for(int i=0;i<n;i++) if(indeg[i] == 0) topo.insert({1,i});
        while(!topo.empty())
        {
            pii tmp = *(topo.begin());
            topo.erase(topo.begin());
            cout<<tmp.X<<" "<<tmp.Y<<"\n";
            for(auto i : adj[tmp.Y])
            {
                indeg[i]--;
                if(indeg[i] == 0) topo.insert({tmp.X + 1,i});
            }
        }
    }
    return 0;
}

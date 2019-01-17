#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n; cin>>n;
        pii p[n+1]; int ans[n+1]{}; for(int i=1;i<=n;i++) {cin>>p[i].X; p[i].Y = i;}
        set<int> tmp; for(int i=1;i<=n;i++) tmp.insert(i);
        sort(p+1,p+n+1,greater<pii>());
        set<int> adj[n+1]; int u,v;
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v;
            adj[u].insert(v); adj[v].insert(u);
        }
        for(int i=1;i<=n;i++)
        {
            u = p[i].Y; vector<int> abc;
            if(tmp.empty()) break;
            for(int j : tmp)
            {
                if(j != u && adj[u].find(j) == adj[u].end()) {ans[j] = u; abc.pb(j);}
            }
            for(int j : abc) tmp.erase(tmp.find(j));
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

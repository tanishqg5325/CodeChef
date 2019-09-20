#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,a,b; cin>>n>>m;
    pii edges[m]; vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        edges[i] = {a, b};
        adj[a].pb(b); adj[b].pb(a);
    }
    int comp[n+1]{}; int k = 1;
    for(int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
    vector<int> noc; noc.pb(0);
    for(int i=1;i<=n;i++)
    {
        if(comp[i]) continue;
        int cnt = 0; a = adj[i].size();
        if(a == 0)
        {
            for(int j=1;j<=n;j++) comp[j] = k;
            noc.pb(n); k++; break;
        }
        for(int j=1;j<adj[i][0];j++) {comp[j] = k; cnt++;}
        for(int j=1;j<a;j++)
        {
            for(int l=adj[i][j-1]+1;l<adj[i][j];l++) {comp[l] = k; cnt++;}
        }
        for(int j=adj[i][a-1]+1;j<=n;j++) {comp[j] = k; cnt++;}
        k++; noc.pb(cnt);
    }
    for(int i=0;i<m;i++)
    {
        a = edges[i].X; b = edges[i].Y;
        if(comp[a] == comp[b]) {cout<<"-1\n"; return 0;}
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size() != n-noc[comp[i]]) {cout<<"-1\n"; return 0;}
    }
    k--;
    int ans = ceil(log2(k));
    if(ans * n > 1000000) {cout<<"-1\n"; return 0;}
    cout<<ans<<"\n";
    vector<bool> compcolor(k+1);
    for(int i=0;i<ans;i++)
    {
        int l = (1 << i); bool color = 0;
        for(int j=1;j<=k;j++)
        {
            for(int p=0;p<l && j<=k;p++,j++)
                compcolor[j] = color;
            j--; color ^= 1;
        }
        for(int i=1;i<=n;i++) cout<<compcolor[comp[i]];
        cout<<"\n";
    }
    return 0;
}

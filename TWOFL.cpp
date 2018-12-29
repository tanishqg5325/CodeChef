#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,m,ar[2000][2000];
vector<int> visited[4000000];
int X[] = {0,1,0,-1};
int Y[] = {1,0,-1,0};
unordered_set<int> vis;

int dfs(int r, int c, int other)
{
    int x,y,ans=1;
    vis.insert(r*m+c);
    for(int i=0;i<4;i++)
    {
        x = r + X[i]; y = c + Y[i];
        if(x >= 0 && x < n && y >= 0 && y < m && vis.find(x*m+y) == vis.end() && find(visited[r*m+c].begin(), visited[r*m+c].end(), x*m+y) == visited[r*m+c].end())
        {
            if(ar[x][y] == ar[r][c]) ans += dfs(x,y,other);
            else if(ar[x][y] == other)
            {
                visited[r*m+c].pb(x*m+y);
                visited[x*m+y].pb(r*m+c);
                ans += dfs(x,y,ar[r][c]);
            }
        }
    }
    return ans;
}

int dfsUtil(int r, int c)
{
    int x,y,ans = 0;
    for(int i=0;i<4;i++)
    {
        x = r + X[i]; y = c + Y[i];
        if(x >= 0 && x < n && y >= 0 && y < m && ar[x][y] != ar[r][c] && find(visited[r*m+c].begin(), visited[r*m+c].end(), x*m+y) == visited[r*m+c].end())
        {
            vis.clear();
            ans = max(dfs(r,c,ar[x][y]), ans);
        }
    }
    return ans;
}

int solve()
{
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans = max(dfsUtil(i,j), ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>ar[i][j];
    int ans = solve();
    if(ans == 0) cout<<m*n<<"\n";
    else cout<<ans<<"\n";
    return 0;
}


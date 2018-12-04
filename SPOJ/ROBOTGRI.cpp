#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;

ll mod = (((ll)1)<<31) - 1;

int x[] = {-1,0,0,1};
int y[] = {0,1,-1,0};

int main()
{
    int n; char c;
    cin>>n;
    ll ar[n][n],dp[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {cin>>c; if(c == '#') ar[i][j] = dp[i][j] = 0; else ar[i][j] = dp[i][j] = 1; }
    if(!ar[0][0] || !ar[n-1][n-1]) {cout<<"INCONCEIVABLE\n"; return 0;}
    bool flag = 1;
    for(int i=n-2;i>=0;i--)
    {
        if(!flag) dp[i][n-1] = 0;
        else if(!dp[i][n-1]) flag = 0;
    }
    flag = 1;
    for(int i=n-2;i>=0;i--)
    {
        if(!flag) dp[n-1][i] = 0;
        else if(!dp[n-1][i]) flag = 0;
    }
    for(int i=n-2;i>=0;i--)
        for(int j=n-2;j>=0;j--)
        {
            if(!dp[i][j]) continue;
            dp[i][j] = (dp[i][j+1] + dp[i+1][j]) % mod;
        }
    if(dp[0][0]) {cout<<dp[0][0]<<"\n"; return 0;}
    bool visited[n][n]{};
    visited[0][0] = 1;
    queue<pii> qu; qu.push(mp(0,0)); pii p,q;
    while(!qu.empty())
    {
        p = qu.front();
        qu.pop();
        for(int i=0;i<4;i++)
        {
            q = mp(p.X + x[i], p.Y + y[i]);
            if(q.X >= 0 && q.X < n && q.Y >= 0 && q.Y < n && !visited[q.X][q.Y] && ar[q.X][q.Y])
            {
                visited[q.X][q.Y] = 1;
                qu.push(q);
            }
        }
    }
    if(visited[n-1][n-1]) cout<<"THE GAME IS A LIE\n";
    else cout<<"INCONCEIVABLE\n";
    return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
using namespace std;

int x[] = {-1,0,1,-1,1,-1,0,1};
int y[] = {-1,-1,-1,0,0,1,1,1},n,m;
char str[1005][1005];

bool check(pii p)
{
    if(p.X >= 0 && p.X < n && p.Y >= 0 && p.Y < m && str[p.X][p.Y] != 'X') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>str[i][j];
        int dist[n][m]; memset(dist, -1, sizeof(dist));
        pii start, end, p;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j] == 'S') start = mp(i,j);
                if(str[i][j] == 'F') end = mp(i,j);
            }
        dist[start.X][start.Y] = 0;
        queue<pii> q; q.push(start);
        while(!q.empty())
        {
            p = q.front(); q.pop();
            for(int i=0;i<8;i++)
            {
                pii qu = p;
                qu.X += x[i]; qu.Y += y[i];
                while(check(qu))
                {
                    if(dist[qu.X][qu.Y] == -1)
                    {
                        dist[qu.X][qu.Y] = dist[p.X][p.Y] + 1;
                        q.push(qu);
                    }
                    else if(dist[qu.X][qu.Y] < (dist[p.X][p.Y] + 1))
                        break;
                    qu.X += x[i]; qu.Y += y[i];
                }
            }
        }
        cout<<dist[end.X][end.Y]<<"\n";
    }
    return 0;
}

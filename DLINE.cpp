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
    int T,n,p,y,s,e;
    cin>>T;
    while(T--)
    {
        cin>>n>>p;
        pii seg[n];
        for(int i=0;i<n;i++) {cin>>y>>s>>e; seg[i] = {y,e};}
        sort(seg, seg+n);
        vector<int> v[2001];
        for(int i=0;i<n;i++) v[seg[i].X].pb(seg[i].Y);
        queue<pair<int,pii>> q;
        if(seg[0].X > p) {cout<<"0\n"; continue;}
        q.push({seg[0].X,{seg[0].X, 0}}); // {y, time, lines}
        int ans=0,i,next_y;
        while(!q.empty())
        {
            pair<int,pii> pre = q.front(); q.pop();
            for(i=pre.X+1;i<=2000;i++)
            {
                if(!v[i].empty()) break;
            }
            next_y = i;
            if(next_y <= 2000 && pre.Y.X + next_y - pre.X <= p) q.push({next_y, {pre.Y.X + next_y - pre.X, pre.Y.Y}});
            for(int i=0;i<v[pre.X].size();i++)
            {
                if(pre.Y.X + v[pre.X][i] <= p)
                    ans = max(ans, pre.Y.Y + i+1);
                if(next_y <= 2000 && pre.Y.X + 2*v[pre.X][i] + next_y - pre.X <= p)
                    q.push({next_y, {pre.Y.X + 2*v[pre.X][i] + next_y - pre.X, pre.Y.Y+i+1}});
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

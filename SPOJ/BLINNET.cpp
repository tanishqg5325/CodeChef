#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,w,v,q; string str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<pii> g[n];
        for(int i=0;i<n;i++)
        {
            cin>>str>>q;
            while(q--)
            {
                cin>>v>>w; v--;
                g[i].pb({w,v});
            }
        }
        bool visited[n]{}; visited[0] = 1; ll ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>>  pq;
        for(auto i : g[0]) pq.push(i);
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            if(visited[tmp.second]) continue;
            visited[tmp.second] = 1;
            ans += tmp.first;
            for(auto i : g[tmp.second]) pq.push(i);
        }
        cout<<ans<<"\n";
    }
	return 0;
}


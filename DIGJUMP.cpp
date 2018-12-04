#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str; cin>>str;
    int n = str.size(),p,t;
    int dist[n]; memset(dist, -1, sizeof(dist)); dist[0] = 0;
    vector<int> pos[10];
    for(int i=0;i<n;i++) pos[str[i] - '0'].pb(i);
    queue<int> q; bool flag[10]{};
    q.push(0);
    while(!q.empty())
    {
        p = q.front(); q.pop(); t = str[p] - '0';
        if(!flag[t])
        {
            for(vector<int>::iterator i = pos[t].begin(); i != pos[t].end(); i++)
                if(dist[*i] == -1)
                {
                    q.push(*i);
                    dist[*i] = dist[p] + 1;
                }
            flag[t] = 1;
        }
        if(p + 1 < n && dist[p+1] == -1) q.push(p+1), dist[p+1] = dist[p] + 1;
        if(p > 0 && dist[p-1] == -1) q.push(p-1), dist[p-1] = dist[p] + 1;
    }
    cout<<dist[n-1]<<"\n";
    return 0;
}

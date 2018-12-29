#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
typedef long long ll;
using namespace std;

struct node
{
    int rank;
    int p;
};

node planet[100000];

void link(int a, int b)
{
    if(a == b) return;
    if(planet[a].rank >= planet[b].rank) planet[b].p = a;
    else
    {
        planet[a].p = b;
        return;
    }
    if(planet[a].rank == planet[b].rank) planet[a].rank++;
}

int find(int n)
{
    if(n != planet[n].p) planet[n].p = find(planet[n].p);
    return planet[n].p;
}

void unionu(int a, int b)
{
    link(find(a), find(b));
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,u,w,v; ll ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        bool isMilk[n];
        for(int i=0;i<n;i++) {cin>>isMilk[i]; planet[i].rank = 0; planet[i].p = i;}
        pair<int,pii> edges[m]; ans = 0;
        for(int i=0;i<m;i++) {cin>>u>>v>>w; u--; v--; edges[i] = {w,{u,v}};}
        sort(edges,edges+m);
        for(int i=0;i<m;i++)
        {
            u = find(edges[i].second.first);
            v = find(edges[i].second.second);
            w = edges[i].first;
            if(isMilk[u] && isMilk[v]) continue;
            if(!isMilk[u] && !isMilk[v])
            {
                if(u == v) continue;
                unionu(u,v); ans += w; continue;
            }
            unionu(u,v); ans += w;
            isMilk[find(u)] = 1;
        }
        bool flag = 1;
        for(int i=0;i<n;i++) if(!isMilk[find(i)]) {flag = 0; break;}
        if(flag) cout<<ans<<"\n";
        else cout<<"impossible\n";
    }
	return 0;
}


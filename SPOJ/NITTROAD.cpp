#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
typedef long long ll;
using namespace std;

struct node
{
    int rank, c;
    int p;
};

node planet[20001];
ll ans;

void linku(int a, int b)
{
    if(a == b) return;
    ans += (planet[a].c * planet[a].c);
    ans += (planet[b].c * planet[b].c);
    if(planet[a].rank >= planet[b].rank)
    {
        planet[b].p = a;
        planet[a].c += planet[b].c;
        ans -= (planet[a].c * planet[a].c);
    }
    else
    {
        planet[a].p = b;
        planet[b].c += planet[a].c;
        ans -= (planet[b].c * planet[b].c);
        return;
    }
    if(planet[a].rank == planet[b].rank) planet[a].rank++;
}

int findu(int n)
{
    if(n != planet[n].p) planet[n].p = findu(planet[n].p);
    return planet[n].p;
}

void unionu(int a, int b)
{
    linku(findu(a), findu(b));
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,u,v,q,x; char c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pii edges[n]; ans = n*(n-1);
        for(int i=1;i<n;i++) {cin>>u>>v; edges[i] = {u,v};}
        cin>>q; vector<int> query; bool roads[n]{}; vector<int> anss;
        while(q--)
        {
            cin>>c;
            if(c == 'Q') {query.pb(0); continue;}
            cin>>x; roads[x] = 1;
            query.pb(x);
        }
        for(int i=1;i<=n;i++) {planet[i].p = i; planet[i].rank = 0; planet[i].c = 1;}
        for(int i=1;i<n;i++)
        {
            if(roads[i]) continue;
            unionu(edges[i].first, edges[i].second);
        }
        q = query.size();
        for(int i=q-1;i>=0;i--)
        {
            if(query[i] == 0) {anss.pb(ans); continue;}
            x = query[i];
            unionu(edges[x].first, edges[x].second);
        }
        int k = anss.size();
        for(int i=k-1;i>=0;i--) cout<<anss[i]/2<<"\n";
        cout<<"\n";
    }
	return 0;
}

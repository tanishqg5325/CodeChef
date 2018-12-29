#include <bits/stdc++.h>
#define pii pair<int,int>
#define pli pair<ll,int>
#define pb push_back
#define X first
#define Y second
#define MAX_N 100000
typedef long long ll;
using namespace std;

ll mod = 1000000000;

struct node
{
    int rank, p;
    ll c;
};

node planet[MAX_N];

void linku(int a, int b)
{
    if(a == b) return;
    if(planet[a].rank >= planet[b].rank)
    {
        planet[b].p = a;
        planet[a].c += planet[b].c;
    }
    else
    {
        planet[a].p = b;
        planet[b].c += planet[a].c;
        return;
    }
    if(planet[a].rank == planet[b].rank) planet[a].rank++;
}

int findu(int n)
{
    if(n != planet[n].p) planet[n].p = findu(planet[n].p);
    return planet[n].p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,u,v,w;
    cin>>n>>m;
    pair<int,pii> edges[m];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w; u--; v--;
        edges[i] = {w,{u,v}};
    }
    sort(edges, edges+m, greater<pair<int,pii>>());
    for(int i=0;i<n;i++) {planet[i].rank = 0; planet[i].p = i; planet[i].c = 1;}
    unsigned long long ans = 0, sum = 0;
    for(int i=0;i<m;i++)
    {
        int p1 = findu(edges[i].Y.X), p2 = findu(edges[i].Y.Y);
        if(p1 != p2)
        {
            sum = (sum + (planet[p1].c * planet[p2].c) % mod) % mod;
            ans = (ans + (edges[i].X * sum) % mod) % mod;
            linku(p1, p2);
        }
        else ans = (ans + (edges[i].X * sum) % mod) % mod;
    }
    cout<<ans<<"\n";
    return 0;
}


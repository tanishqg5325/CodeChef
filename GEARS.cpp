#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct node
{
    int rank, p, c;
};

node gear[100000]; vector<int> *adj;

void linku(int a, int b)
{
    if(a == b) return;
    if(gear[a].rank >= gear[b].rank) {gear[b].p = a; gear[a].c += gear[b].c;}
    else
    {
        gear[a].p = b; gear[b].c += gear[a].c;
        return;
    }
    if(gear[a].rank == gear[b].rank) gear[a].rank++;
}

int findu(int n)
{
    if(n != gear[n].p) gear[n].p = findu(gear[n].p);
    return gear[n].p;
}

ll gcd(ll m, ll n) {if(n == 0) return m; return gcd(n,m%n);}

void dfs(int v, bool pres, bool color[], unordered_set<int> &visited)
{
    color[v] = pres;
    visited.insert(v);
    for(auto i : adj[v]) if(visited.find(i) == visited.end()) dfs(i, pres^1, color, visited);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t,x,y,c,v,xp,yp; ll num,den,g;
    cin>>n>>m;
    ll teeth[n]; bool blckd[n]{},color[n]{}; adj = new vector<int>[n];
    for(int i=0;i<n;i++) {gear[i].rank = 0; gear[i].p = i; gear[i].c = 1;}
    for(int i=0;i<n;i++) cin>>teeth[i];
    while(m--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>c;
            teeth[x-1]=c;
        }
        else if(t==2)
        {
            cin>>x>>y; x--; y--;
            xp = findu(x); yp = findu(y);
            if(blckd[xp] || blckd[yp]) blckd[xp] = blckd[yp] = 1;
            else
            {
                if(xp != yp)
                {
                    if(color[x] == color[y])
                    {
                        unordered_set<int> visited;
                        if(gear[xp].c > gear[yp].c) dfs(y, color[y]^1, color, visited);
                        else dfs(x, color[x]^1, color, visited);
                    }
                    adj[x].pb(y); adj[y].pb(x);
                    linku(xp, yp);
                }
                else if(color[x] == color[y]) blckd[xp] = 1;
            }
        }
        else if(t==3)
        {
            cin>>x>>y>>v; x--;y--;
            xp = findu(x); yp = findu(y);
            if(blckd[xp] || blckd[yp] || xp != yp) cout<<"0\n";
            else
            {
                num = v * teeth[x], den = teeth[y];
                g = gcd(num, den); num /= g; den /= g;
                if(color[x] != color[y]) num = -num;
                cout<<num<<"/"<<den<<"\n";
            }
        }
    }
    return 0;
}

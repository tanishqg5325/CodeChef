#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int ans[1000000];

struct node
{
    vector<pii> v;
    vector<pair<pii, int>> q;
};

int find_cf(int idx, int tree[]) {int sum = 0; for(;idx;idx -= (idx & -idx)) sum += tree[idx]; return sum;}
void update(int idx, int tree[], int n) {for(;idx <= n;idx += (idx & -idx)) tree[idx]++;}

bool compare1(pii &p1, pii &p2) {return p1.Y > p2.Y;}
bool compare2(pair<pii, int> &p1, pair<pii, int> &p2) {return p1.X.Y > p2.X.Y;}

void dodgers(node st[], int si, int ss, int se)
{
    if(ss != se) {int mid = (ss + se) >> 1; dodgers(st, si<<1, ss, mid); dodgers(st, (si<<1) | 1, mid+1, se);}
    if(st[si].q.empty()) return;
    vector<pii> &v = st[si].v;
    int n = v.size(); for(int i=0;i<n;i++) v[i].X = i+1;
    sort(v.begin(), v.end(), compare1); int tree[n+1]{};
    int k = n-1; n++;
    for(auto &i : st[si].q)
    {
        while(k >= 0 && v[k].Y > i.X.Y) {update(v[k].X, tree, n); k--;}
        ans[i.Y] += find_cf(i.X.X, tree);
    }
}

void dfs(int u, bool visited[], vector<int> adj[], int order[], int &k)
{
    visited[u] = 1; order[u] = k++;
    for(int &i : adj[u])
        if(!visited[i])
            dfs(i, visited, adj, order, k);
}

void constructSt(pii ar[], int si, int ss, int se, node st[])
{
    if(ss == se) {st[si].v.pb(ar[ss]); return;}
    int mid = (ss + se) >> 1;
    constructSt(ar, si<<1, ss, mid, st);
    constructSt(ar, (si<<1) | 1, mid+1, se, st);
    vector<pii> &v1 = st[si<<1].v;
    vector<pii> &v2 = st[(si<<1) | 1].v;
    int n1 = v1.size(), n2 = v2.size(), a = 0, b = 0, c = 0;
    st[si].v.resize(n1+n2);
    while(a < n1 && b < n2)
    {
        if(v1[a].X <= v2[b].X) {if(v1[a].Y > se) st[si].v[c++] = v1[a]; a++;}
        else {if(v2[b].X < ss) st[si].v[c++] = v2[b]; b++;}
    }
    while(a < n1) {if(v1[a].Y > se) st[si].v[c++] = v1[a]; a++;}
    while(b < n2) {if(v2[b].X < ss) st[si].v[c++] = v2[b]; b++;}
    st[si].v.resize(c);
}

void solve(node st[], int si, int ss, int se, int l, int r, int i)
{
    if(se < l || ss > r) return;
    if(ss >= l && se <= r)
    {
        auto it = lower_bound(st[si].v.begin(), st[si].v.end(), make_pair(l ,0));
        if(it == st[si].v.begin()) return;
        l = it - st[si].v.begin();
        if(l <= 100)
        {
            for(int j=0;j<l;j++) if(st[si].v[j].Y > r) ans[i]++;
            return;
        }
        st[si].q.pb({{l, r}, i});
        return;
    }
    int mid = (ss + se) >> 1;
    solve(st, si<<1, ss, mid, l, r, i);
    solve(st, (si<<1) | 1, mid+1, se, l, r, i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,q,s,a,b; cin>>T;
    while(T--)
    {
        cin>>n>>m>>q>>s; vector<int> adj[n+1];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            adj[a].pb(b); adj[b].pb(a);
        }
        int order[n+1]; bool visited[n+1]{}; int k = 1;
        for(int i=1;i<=n;i++) if(!visited[i]) dfs(i, visited, adj, order, k);
        pii val[n+1];
        for(int i=1;i<=n;i++)
        {
            val[i] = {0, n+1};
            for(int &j : adj[i])
            {
                if(j < i && order[j] < order[i] && j > val[i].X) val[i].X = j;
                else if(j > i && order[j] < order[i] && j < val[i].Y) val[i].Y = j;
            }
        }
        node st[3*n+3]; constructSt(val, 1, 1, n, st);
        pair<pii, int> qu[q];
        for(int i=0;i<q;i++)
        {
            cin>>a>>b; ans[i] = 0;
            if(a > b) swap(a, b);
            qu[i] = {{a, b}, i};
        }
        sort(qu, qu+q, compare2);
        for(int i=0;i<q;i++) solve(st, 1, 1, n, qu[i].X.X, qu[i].X.Y, qu[i].Y);
        dodgers(st, 1, 1, n);
        for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
    }
    return 0;
}

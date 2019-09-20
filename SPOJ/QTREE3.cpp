#include <bits/stdc++.h>
#define pb push_back
#define N 100000
#define LN 17
using namespace std;

vector<int> adj[N];
int pa[LN][N], baseArray[N], ptr, rev[N+1];
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int subsize[N], st[N*3];

void make_tree(int si, int ss, int se)
{
	if(ss == se) {st[si] = N; return;}
	int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
	make_tree(c1, ss, mid);
	make_tree(c2, mid+1, se);
	st[si] = N;
}

void update_tree(int si, int ss, int se, int idx)
{
    if(ss == se) {st[si] = ((st[si] == N) ? ss : N); return;}
    int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
    if(idx <= mid) update_tree(c1, ss, mid, idx);
    else update_tree(c2, mid+1, se, idx);
    st[si] = min(st[c1], st[c2]);
}

int query_tree(int si, int ss, int se, int l, int r)
{
    if(l == ss && r == se) return st[si];
    int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
    if(l > mid) return query_tree(c2, mid+1, se, l, r);
    if(r <= mid) return query_tree(c1, ss, mid, l, r);
    return min(query_tree(c1, ss, mid, l, mid), query_tree(c2, mid+1, se, mid+1, r));
}

int query_up(int u, int v)
{
	int uchain, vchain = chainInd[v], ans = N;
	while(1)
    {
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			ans = min(ans, query_tree(0, 0, ptr - 1, posInBase[v], posInBase[u]));
			break;
		}
		ans = min(ans, query_tree(0, 0, ptr - 1, posInBase[chainHead[uchain]], posInBase[u]));
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}

void HLD(int curNode, int prev)
{
	if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
	chainInd[curNode] = chainNo;
	rev[ptr] = curNode + 1;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = N;

	int sc = -1, k = adj[curNode].size();
	for(int i=0;i<k;i++)
		if(adj[curNode][i] != prev && (sc == -1 || subsize[sc] < subsize[adj[curNode][i]]))
			sc = adj[curNode][i];

	if(sc != -1) HLD(sc, curNode);

	for(int i=0; i<k; i++)
		if(adj[curNode][i] != prev && adj[curNode][i] != sc)
        {
			chainNo++;
			HLD(adj[curNode][i], curNode);
		}
}

void dfs(int curr, int par)
{
    pa[0][curr] = par; subsize[curr] = 1;
    for(int i : adj[curr])
        if(i != par)
        {
            dfs(i, curr);
            subsize[curr] += subsize[i];
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,u,v,k; cin>>n>>q; ptr = chainNo = 0; chainHead[0] = rev[N] = -1;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
        chainHead[i] = -1;
    }
    for(int i=0;i<LN;i++) for(int j=0;j<n;j++) pa[i][j] = -1;
    dfs(0, -1); HLD(0, -1); make_tree(0, 0, ptr - 1);
    for(int i=1;i<LN;i++)
			for(int j=0;j<n;j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
    while(q--)
    {
        cin>>k>>v; v--;
        if(k == 0) update_tree(0, 0, ptr - 1, posInBase[v]);
        else cout<<rev[query_up(v, 0)]<<"\n";
    }
    return 0;
}

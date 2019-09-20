#include <iostream>
#include <vector>
using namespace std;

#define root 0
#define N 10000
#define LN 14

vector<int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*3];

void make_tree(int si, int ss, int se)
{
	if(ss == se) {st[si] = baseArray[ss]; return;}
	int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
	make_tree(c1, ss, mid);
	make_tree(c2, mid+1, se);
	st[si] = max(st[c1], st[c2]);
}

void update_tree(int si, int ss, int se, int idx, int val)
{
    if(ss == se) {st[si] = val; return;}
    int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
    if(idx <= mid) update_tree(c1, ss, mid, idx, val);
    else update_tree(c2, mid+1, se, idx, val);
    st[si] = max(st[c1], st[c2]);
}

int query_tree(int si, int ss, int se, int l, int r)
{
    if(l == ss && r == se) return st[si];
    int c1 = (si << 1) + 1, c2 = c1 + 1, mid = (ss + se) >> 1;
    if(l > mid) return query_tree(c2, mid+1, se, l, r);
    if(r <= mid) return query_tree(c1, ss, mid, l, r);
    return max(query_tree(c1, ss, mid, l, mid), query_tree(c2, mid+1, se, mid+1, r));
}

int LCA(int u, int v)
{
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0;i<LN;i++) if((diff>>i)&1) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1;i>=0;i--)
        if(pa[i][u] != pa[i][v])
        {
            u = pa[i][u];
            v = pa[i][v];
        }
	return pa[0][u];
}

int query_up(int u, int v)
{
	if(u == v) return 0;
	int uchain, vchain = chainInd[v], ans = -1;
	while(1)
    {
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			if(u == v) break;
			ans = max(ans, query_tree(0, 0, ptr - 1, posInBase[v]+1, posInBase[u]));
			break;
		}
		ans = max(ans, query_tree(0, 0, ptr - 1, posInBase[chainHead[uchain]], posInBase[u]));
		u = chainHead[uchain];
		u = pa[0][u];
	}
	return ans;
}

void HLD(int curNode, int cost, int prev)
{
	if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = cost;

	int sc = -1, ncost,k = adj[curNode].size();
	for(int i=0;i<k;i++)
		if(adj[curNode][i] != prev && (sc == -1 || subsize[sc] < subsize[adj[curNode][i]]))
        {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}

	if(sc != -1) HLD(sc, ncost, curNode);

	for(int i=0; i<k; i++)
		if(adj[curNode][i] != prev && adj[curNode][i] != sc)
        {
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
}

void dfs(int cur, int prev, int _depth=0)
{
	pa[0][cur] = prev; depth[cur] = _depth; subsize[cur] = 1;
	int k = adj[cur].size();
	for(int i=0;i<k;i++)
		if(adj[cur][i] != prev)
        {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t,n,u,v,c,a,b,lca; string str; cin>>t;
	while(t--)
    {
		cin>>n; ptr = chainNo = 0;
		for(int i=0;i<n;i++)
        {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0;j<LN;j++) pa[j][i] = -1;
		}
		for(int i=1;i<n;i++)
		{
			cin>>u>>v>>c; u--; v--;
			adj[u].push_back(v); adj[v].push_back(u);
			costs[u].push_back(c); costs[v].push_back(c);
			indexx[u].push_back(i-1); indexx[v].push_back(i-1);
		}
		dfs(root, -1); HLD(root, -1, -1);
		make_tree(0, 0, ptr - 1);
		for(int i=1;i<LN;i++)
			for(int j=0;j<n;j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

        cin>>str;
		while(str[0] != 'D')
        {
			cin>>a>>b; a--;
			if(str[0] == 'Q')
            {
                b--; lca = LCA(a, b);
                cout<<max(query_up(a, lca), query_up(b, lca))<<"\n";
            }
            else
            {
                u = otherEnd[a];
                update_tree(0, 0, ptr - 1, posInBase[u], b);
            }
            cin>>str;
		}
	}
}

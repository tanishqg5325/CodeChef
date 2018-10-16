#include <bits/stdc++.h>
using namespace std;

int num = 1000000000, inf = INT_MAX;

struct node
{
    vector<int> v;
};

vector<int> constructST(int arr[], int ss, int se, node st[], int si)
{
    if (ss == se) { vector<int> v(1); v[0] = arr[ss]; st[si].v = v; return v; }
    int mid = (ss + se)/2,m,n;
    vector<int> v1 = constructST(arr, ss, mid, st, 2*si+1); m = v1.size();
    vector<int> v2 = constructST(arr, mid+1, se, st, 2*si+2); n = v2.size();
    vector<int> v(m+n);
    int i(0),j(0),k(0);
    while(i<m && j<n)
    {
        if(v1[i]<=v2[j]) v[k++] = v1[i++];
        else v[k++] = v2[j++];
    }
    while(i<m) v[k++] = v1[i++];
    while(j<n) v[k++] = v2[j++];
    st[si].v = v;
    return v;
}

int ans(node st[], int ss, int se, int l, int r, int i, int x)
{
    if(ss > r || se < l) return inf;
    if(ss >= l && se <= r)
    {
        vector<int> v = st[i].v; int n = v.size();
        if(x >= v[n-1]) return v[n-1];
        if(x <= v[0]) return v[0];
        int lower = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(abs(v[lower-1]-x) <= abs(v[lower]-x)) return v[lower-1];
        else return v[lower];
    }
    int mid = (ss + se)/2;
    int x1 = ans(st, ss, mid, l, r, 2*i+1, x);
    int x2 = ans(st, mid+1, se, l, r, 2*i+2, x);
    if(abs(x-x1) < abs(x-x2)) return x1;
    else if(abs(x-x1) > abs(x-x2)) return x2;
    return min(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,l,r,k;
    cin>>n>>q;
    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    int x = (int)(ceil(log2(n)));
    int max_size = (1<<(x+1)) - 1;
    node st[max_size];
    constructST(ar,0,n-1,st,0);
    while(q--)
    {
        cin>>l>>r>>k;
        l--; r--;
        cout<<ans(st, 0, n-1, l, r, 0, num-k)<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node
{
    vector<int> v;
};

vector<int> constructST(int arr[], int ss, int se, node st[], int si)
{
    if (ss == se) {vector<int> v(1); v[0] = arr[ss]; st[si].v = v; return v; }
    int mid = (ss + se) >> 1,m,n;
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

int solve(int si, int ss, int se, node st[], int l, int r, int k)
{
    if(l == ss && r == se)
        return (st[si].v.end() - upper_bound(st[si].v.begin(), st[si].v.end(), k));
    int mid = (ss + se) >> 1;
    if(l > mid) return solve(2*si+2, mid+1, se, st, l, r, k);
    if(r <= mid) return solve(2*si+1, ss, mid, st, l, r, k);
    return solve(2*si+1, ss, mid, st, l, mid, k) + solve(2*si+2, mid+1, se, st, mid+1, r, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,l,r,k;
    cin>>n; int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    int x = (int)(ceil(log2(n)));
    int max_size = (1<<(x+1)) - 1;
    node st[max_size]; cin>>q;
    constructST(ar, 0, n-1, st, 0);
    int res = 0;
    while(q--)
    {
        cin>>l>>r>>k;
        l ^= res; r^= res; k ^= res;
        if(l < 1) l = 1;
        if(r > n) r = n;
        if(l > r) {res = 0; cout<<res<<"\n"; continue;}
        l--; r--;
        res = solve(0, 0, n-1, st, l, r, k);
        cout<<res<<"\n";
    }
    return 0;
}

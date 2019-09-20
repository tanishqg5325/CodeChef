#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define N 300001
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll mod = 1000000007, fact[N];

ll power(ll n, int p)
{
	ll ans = 1;
    while(p)
	{
        if(p & 1) ans = (ans * n) % mod;
        p = p >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

int compress(int ar[], int n)
{
    set<int> s(ar, ar+n);
    int k = 0; unordered_map<int, int> dict;
    for(int i : s) dict[i] = k++;
    for(int i=0;i<n;i++) ar[i] = dict[ar[i]];
    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q,new_l,b; ll l1,l2,r1,r2,l,r,ans,tmp,num,den;
    cin>>n>>q; int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    int dist = compress(ar, n); vector<int> pos[dist];
    for(int i=0;i<n;i++) pos[ar[i]].pb(i);
    fact[0] = 1; for(int i=1;i<=n;i++) fact[i] = (fact[i-1] * i) % mod;
    int block_sz = sqrt(n);
    int k = ceil(1.0 * n / block_sz); vector<pii> st[k];
    vector<int> freq(dist);
    for(int i=0;i<k;i++)
    {
        ans = 1; b = i*block_sz; st[i].resize(n-b);
        for(int j=b;j<n;j++)
        {
            freq[ar[j]]++;
            ans = ans * freq[ar[j]]; if(ans >= mod) ans %= mod;
            st[i][j-b] = {freq[ar[j]], ans};
        }
        fill(freq.begin(), freq.end(), 0);
    }
    ans = 0;
    while(q--)
    {
        cin>>l1>>l2>>r1>>r2;
        l = (l1*ans + l2) % n; r = (r1*ans + r2) % n; if(l > r) swap(l, r);
        if(l % block_sz == 0) tmp = st[l/block_sz][r-l].Y;
        else if(r - l <= block_sz)
        {
            tmp = 1; vector<int> tmp1;
            for(int i=l;i<=r;i++)
            {
                if(freq[ar[i]] == 0) tmp1.pb(ar[i]);
                freq[ar[i]]++;
                tmp = tmp * freq[ar[i]];
                if(tmp >= mod) tmp %= mod;
            }
            for(int i : tmp1) freq[i] = 0;
        }
        else
        {
            new_l = block_sz * (l/block_sz + 1);
            tmp = st[new_l/block_sz][r-new_l].Y;
            vector<int> tmp1;
            for(int i=l;i<new_l;i++)
            {
                if(freq[ar[i]] == 0) tmp1.pb(ar[i]);
                freq[ar[i]]++;
            }
            num = den = 1;
            for(int i : tmp1)
            {
                b = *(upper_bound(pos[i].begin(), pos[i].end(), r) - 1);
                if(b < new_l) b = 0;
                else b = st[new_l/block_sz][b-new_l].X;
                num = num * fact[b+freq[i]]; if(num >= mod) num %= mod;
                den = den * fact[b]; if(den >= mod) den %= mod;
                freq[i] = 0;
            }
            tmp = tmp * num; if(tmp >= mod) tmp %= mod;
            tmp = tmp * power(den, mod-2); if(tmp >= mod) tmp %= mod;
        }
        ans = fact[r-l+1] * power(tmp, mod-2);
        if(ans >= mod) ans %= mod;
        cout<<ans<<"\n";
    }
    return 0;
}

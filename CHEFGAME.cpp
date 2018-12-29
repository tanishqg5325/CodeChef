#include <bits/stdc++.h>
#define pli pair<ll,int>
#define pb push_back
#define inf LLONG_MAX
typedef long long ll;
using namespace std;

ll mod = 747474747;
ll points[6666][5], graph[6666][6666];
bool mstSet[6666]; ll key[6666];
int n,d;

ll dist(int p, int q)
{
    ll ans = 0;
    for(int i=0;i<d;i++)
        ans += (points[p][i] - points[q][i]) * (points[p][i] - points[q][i]);
    return ans;
}

int maxKey()
{
    ll max = -inf; int max_index;
    for(int i=0;i<n;i++)
        if(!mstSet[i] && key[i] > max)
            max = key[i], max_index = i;
    return max_index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,u; ll ans; cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++) for(int j=0;j<d;j++) cin>>points[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) graph[i][j] = dist(i,j);
        for(int i=0;i<n;i++) mstSet[i] = 0, key[i] = -inf;
        ans = 1; key[0] = 0;
        for(int i=0;i<n;i++)
        {
            u = maxKey(); mstSet[u] = 1;
            if(key[u]) ans = (ans * (key[u] % mod)) % mod;
            for(int j=0;j<n;j++) if(!mstSet[j] && graph[u][j] > key[j]) key[j] = graph[u][j];
        }
        cout<<ans<<"\n";
    }
    return 0;
}

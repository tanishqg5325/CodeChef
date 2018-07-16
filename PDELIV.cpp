#include <bits/stdc++.h>
#include <limits>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,tmp;
    cin>>n>>m;
    unordered_set<int> pizza[m];
    ll s[n],p[n],c[m],k[m],cost,mincost;
    for(int i=0;i<n;i++) cin>>s[i]>>p[i];
    for(int i=0;i<m;i++)
    {
        cin>>c[i]>>k[i];
        for(int j=0;j<k[i];j++)
        {
            cin>>tmp;
            pizza[i].insert(tmp-1);
        }
    }
    for(int i=0;i<m;i++)
    {
        mincost = numeric_limits<ll>::max();
        for(int j=0;j<n;j++)
        {
            if (pizza[i].find(j) == pizza[i].end())
            {
                cost = p[j]+(s[j]-c[i])*(s[j]-c[i]);
                if(cost<mincost) mincost=cost;
            }
        }
        cout<<mincost<<"\n";
    }
    return 0;
}

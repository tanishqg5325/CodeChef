#include <bits/stdc++.h>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll ar[n];
        for(ll i=0;i<n;i++) cin>>ar[i];
        queue <ll> q;
        ll cost=0,max_cities=0,cost_spent=0;
        for(ll i=0;i<n;i++)
        {
            q.push(i);
            cost += ar[i];
            while(!q.empty() && cost>k)
            {
                cost -= ar[q.front()];
                q.pop();
            }
            if(q.size()>max_cities)
            {
                max_cities = q.size();
                cost_spent = cost;
            }
            else if(q.size() == max_cities && cost>cost_spent)
                cost_spent = cost;
        }
        cout<<max_cities<<" "<<k-cost_spent<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; ll a,b,c;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>n;
        priority_queue<ll, vector<ll>> pq1;
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        ll ans = 1,m,f; pq1.push(1);
        for(int i=2;i<=n;i++)
        {
            m = pq1.top();
            f = (a*m + b*i + c) % mod;
            ans += f;
            if(i%2 == 0)
            {
                if(f >= pq1.top()) pq2.push(f);
                else
                {
                    pq2.push(pq1.top());
                    pq1.pop(); pq1.push(f);
                }
            }
            else
            {
                if(f <= pq2.top()) pq1.push(f);
                else
                {
                    pq1.push(pq2.top());
                    pq2.pop(); pq2.push(f);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

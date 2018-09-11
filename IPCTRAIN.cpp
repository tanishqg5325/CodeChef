#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct trainer
{
    ll d,t,s;
    bool operator < (const trainer &other) const { return d < other.d; }
};

struct compare
{
    bool operator()(const trainer & a, const trainer & b)
    {
        return (a.s <= b.s);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,d,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        trainer tr[n],curr; k=0;
        for(int i=0;i<n;i++) cin>>tr[i].d>>tr[i].t>>tr[i].s;
        sort(tr,tr+n);
        priority_queue <trainer, vector<trainer>, compare> pq;
        for(int i=1;i<=d;i++)
        {
            while(k<n && tr[k].d == i) pq.push(tr[k]), k++;
            if(!pq.empty())
            {
                curr = pq.top();
                curr.t--;
                pq.pop();
                if(curr.t) pq.push(curr);
            }
        }
        ll ans = 0;
        while(!pq.empty())
        {
            curr = pq.top();
            ans += (curr.s * curr.t);
            pq.pop();
        }
        cout<<ans<<"\n";
    }
    return 0;
}

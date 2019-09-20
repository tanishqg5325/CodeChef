#include <bits/stdc++.h>
#define pb push_back
#define P first
#define C second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,q,k,l,r; cin>>T;
    while(T--)
    {
        cin>>n>>q>>k>>l>>r; pii coke[n];
        for(int i=0;i<n;i++) cin>>coke[i].C>>coke[i].P;
        sort(coke, coke+n); set<int> tmp;
        for(int i=1;i<=q;i++) tmp.insert(i);
        int ans[q+1]; for(int i=1;i<=q;i++) ans[i] = INT_MAX;
        int idx = 1;
        if(k < l)
        {
            for(int i=0;i<n;i++)
            {
                if(coke[i].C <= l) continue;
                if(coke[i].C > r+q) continue;
                int left = max(coke[i].C - r, 1);
                int right = min(coke[i].C - l, q);
                auto it = tmp.lower_bound(left);
                vector<int> v;
                while(it != tmp.end() && (*it) <= right)
                {
                    ans[(*it)] = coke[i].P;
                    v.pb(*it);
                    it++;
                }
                for(int i : v) tmp.erase(i);
            }
        }
        else if(k > r)
        {
            for(int i=0;i<n;i++)
            {
                if(coke[i].C >= r) continue;
                if(coke[i].C < l-q) continue;
                int left = max(l - coke[i].C, 1);
                int right = min(r - coke[i].C, q);
                auto it = tmp.lower_bound(left);
                vector<int> v;
                while(it != tmp.end() && (*it) <= right)
                {
                    ans[(*it)] = coke[i].P;
                    v.pb(*it);
                    it++;
                }
                for(int i : v) tmp.erase(i);
            }
        }
        else
        {
            // l <= k <= r
            idx = n;
            for(int i=0;i<n;i++)
            {
                if(coke[i].C >= l && coke[i].C <= r)
                {
                    for(int j=1;j<=idx;j++) ans[j] = coke[i].P;
                    break;
                }
                else if(coke[i].C < l)
                {
                    for(;idx >= l-coke[i].C && idx >= 1;idx--) ans[idx] = coke[i].P;
                }
                else
                {
                    for(;idx >= coke[i].C - r && idx >= 1;idx--) ans[idx] = coke[i].P;
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            if(ans[i] == INT_MAX) cout<<"-1 ";
            else cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

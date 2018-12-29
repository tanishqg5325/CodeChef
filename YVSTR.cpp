#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
typedef long long ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n; string str; vector<pii> maxmin[26][26];
    cin>>t;
    while(t--)
    {
        cin>>n>>str;
        ll ans = 0; int maxl[26]{},i=0; int len = 1; vector<int> v; v.pb(0);
        for(int i=1;i<n;i++)
        {
            if(str[i] == str[i-1]) {len++; continue;}
            maxl[str[i-1] - 'a'] = max(maxl[str[i-1] - 'a'], len);
            len = 1; v.pb(i);
        }
        maxl[str[n-1] - 'a'] = max(maxl[str[n-1] - 'a'], len);
        for(int i=0;i<26;i++) ans += maxl[i];
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) maxmin[i][j].clear();
        int k = v.size(); int l1,l2,k1,k2;
        for(int i=0;i<k-1;i++)
        {
            l1 = v[i+1] - v[i];
            l2 = ((i+2 < k) ? v[i+2] - v[i+1] : n - v[i+1]);
            k1 = str[v[i]] - 'a', k2 = str[v[i+1]] - 'a';
            maxmin[k1][k2].pb({l1,l2});
        }
        ll one = 1; int last;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(maxmin[i][j].empty()) continue;
                sort(maxmin[i][j].begin(), maxmin[i][j].end());
                vector<pii> tmp;
                for(auto P : maxmin[i][j])
                {
                    while(!tmp.empty() && P.second >= tmp.back().second) tmp.pop_back();
                    tmp.pb(P);
                }
                last = 0;
                for(auto P : tmp)
                {
                    ans += one * P.second * (P.first - last);
                    last = P.first;
                }
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}

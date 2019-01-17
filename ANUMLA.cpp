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
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int b = 1<<n,a; multiset<int> ms;
        for(int i=0;i<b;i++) {cin>>a; ms.insert(a);}
        ms.erase(0); vector<int> ans,temp; temp.pb(0);
        while(!ms.empty())
        {
            int c = *(ms.begin());
            ans.pb(c); vector<int> tmp;
            for(auto i : temp)
            {
                ms.erase(ms.find(i + c));
                tmp.pb(i+c);
            }
            for(auto i : tmp) temp.pb(i);
        }
        for(auto i : ans) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

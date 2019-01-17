#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; string str; cin>>T;
    while(T--)
    {
        cin>>str;
        n = str.size();
        int mini[26],maxi[26];
        for(int i=0;i<26;i++) {mini[i] = INT_MAX; maxi[i] = INT_MIN;}
        for(int i=0;i<n;i++)
        {
            int t = str[i] - 'a';
            mini[t] = min(mini[t], i);
            maxi[t] = max(maxi[t], i);
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            if(maxi[i] != INT_MIN && mini[25-i] != INT_MAX)
                ans = max(ans, maxi[i] - mini[25-i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

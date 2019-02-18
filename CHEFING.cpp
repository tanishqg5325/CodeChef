#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; bool ans[26],temp[26]; cin>>T;
    while(T--)
    {
        cin>>n; string str[n];
        for(int i=0;i<n;i++) cin>>str[i];
        memset(ans, 1, sizeof(ans));
        for(int i=0;i<n;i++)
        {
            int l = str[i].size();
            memset(temp, 0, sizeof(temp));
            for(int j=0;j<l;j++) temp[str[i][j]-'a'] = 1;
            for(int i=0;i<26;i++) ans[i] = ans[i] && temp[i];
        }
        int ans1 = 0;
        for(int i=0;i<26;i++) if(ans[i]) ans1++;
        cout<<ans1<<"\n";
    }
    return 0;
}

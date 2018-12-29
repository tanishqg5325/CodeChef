#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,k,c;
    cin>>T;
    while(T--)
    {
        cin>>n; int ar[n+1]; vector<int> v[n+1]; bool occur[n+1]{};
        for(int i=1;i<=n;i++) {cin>>ar[i]; v[ar[i]].pb(i); occur[ar[i]] = 1;}
        bool flag = 0;
        for(int i=1;i<=n;i++)
        {
            k = v[i].size();
            if(k < 2) continue;
            c = 0;
            for(int j=0;j<k;j++) if(occur[v[i][j]]) c++;
            if(c >= 2) {flag=1; break;}
        }
        if(flag) cout<<"Truly Happy\n";
        else cout<<"Poor Chef\n";
    }
    return 0;
}

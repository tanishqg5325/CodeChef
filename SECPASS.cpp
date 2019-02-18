#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,l; string str; cin>>T;
    while(T--)
    {
        cin>>n>>str;
        for(l=1;l<n;l++) if(str[l] == str[0]) break;
        if(l == n) {cout<<str<<"\n"; continue;}
        int ans = n;
        for(int i=l;i<n;i++)
        {
            int j = 1;
            if(str[i] == str[0])
            {
                while(i+j < n && j < l && str[i+j] == str[j]) j++;
                ans = min(ans, j);
            }
            if(i+j < n) i = i+j-1;
        }
        cout<<str.substr(0, ans)<<"\n";
    }
    return 0;
}

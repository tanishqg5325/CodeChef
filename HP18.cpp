#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,a,b,y;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b;
        if(a == b)
        {
            int ans = 0;
            for(int i=0;i<n;i++) {cin>>y; if(y%a == 0) ans++;}
            if(ans) cout<<"BOB\n";
            else cout<<"ALICE\n";
            continue;
        }
        int ans1 = 0, ans2 = 0,ans3 = 0;
        for(int i=0;i<n;i++)
        {
            cin>>y;
            if(y % a == 0 && y % b == 0) ans3++;
            else if(y % a == 0) ans1++;
            else if(y % b == 0) ans2++;
        }
        if(ans3 == 0)
        {
            if(ans1 > ans2) cout<<"BOB\n";
            else cout<<"ALICE\n";
        }
        else
        {
            if(ans1 >= ans2) cout<<"BOB\n";
            else cout<<"ALICE\n";
        }
    }
    return 0;
}

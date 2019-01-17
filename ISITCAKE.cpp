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
    int T;
    cin>>T;
    while(T--)
    {
        int ans = 0,a;
        for(int i=0;i<10;i++) for(int j=0;j<10;j++) {cin>>a; if(a<=30) ans++;}
        if(ans>=60) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}

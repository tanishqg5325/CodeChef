#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m; cin>>T;
    while(T--)
    {
        cin>>n>>m; int ans,r,c;
        for(int k=0;k<m*n;k++)
        {
            ans = (m*n-1)/(k+1) + 1;
            ans *= 2;
            for(int i=0;i<m*n;i+=(k+1))
            {
                r = i/m;
                c = i % m;
                if((r + c*n) % (k+1) == 0) ans--;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; ll y1,m1,d1,y2,m2,d2;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ar[n+1]; ll sum=0;
        for(int i=1;i<=n;i++) {cin>>ar[i]; sum+=ar[i];}
        cin>>y1>>m1>>d1>>y2>>m2>>d2;
        ll ans = (y2 - y1 - 1) * sum + 1;
        ans += d2;
        for(int i=1;i<m2;i++) ans += ar[i];
        for(int i=m1+1;i<=n;i++) ans += ar[i];
        ans += (ar[m1] - d1);
        for(int i=y1;i<y2;i++) if(i%4 == 0) ans ++;
        cout<<ans<<"\n";
    }
    return 0;
}

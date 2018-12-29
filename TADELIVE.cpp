#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    pii diff[n];
    for(int i=0;i<n;i++) diff[i] = {abs(a[i]-b[i]), i};
    sort(diff, diff + n, greater<pii>());
    int c1 = 0, c2=0, j, ans=0;
    for(int i=0;i<n;i++)
    {
        int j = diff[i].second;
        if(a[j] > b[j])
        {
            if(c1 < x) ans += a[j], c1++;
            else ans += b[j], c2++;
        }
        else
        {
            if(c2 < y) ans += b[j], c2++;
            else ans += a[j], c1++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

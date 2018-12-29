#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int steps[1001],k[500],h[500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,j; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) {cin>>h[i]; h[i] *= 2;}
        for(int i=0;i<n;i++) cin>>k[i];
        sort(k, k+n); steps[0] = 0;
        for(int i=1;i<=1000;i++) steps[i] = inf;
        for(int i=1;i<=1000;i++)
        {
            j = 0;
            while(j < n && k[j] <= i)
            {
                if(steps[i-k[j]] != inf)
                    steps[i] = min(steps[i], 1 + steps[i-k[j]]);
                j++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans += steps[h[i]];
        cout<<ans<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

ll func(int ar[], int n)
{
    ll ans = 0; int dist=1;
    for(int i=1;i<n;i++) if(ar[i]!=ar[i-1]) dist++;
    pair<int,ll> p[dist];
    int k=0;
    p[0].fi = ar[0];
    p[0].se = 1;
    for(int i=1;i<n;i++)
    {
        if(ar[i]!=ar[i-1]) { k++; p[k].fi = ar[i]; p[k].se = 1; }
        else p[k].se++;
    }
    for(int i=0;i<dist-1;i++)
    {
        if((p[i].fi^p[i+1].fi) == 2) ans += (p[i].se*p[i+1].se);
        else if(i<dist-2 && (p[i].fi^p[i+2].fi) == 2) ans += (p[i].se*p[i+2].se);
    }
    for(int i=0;i<dist;i++) ans += (p[i].se*(p[i].se - 1)/2);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n; ll evens,odds,ans;
    cin>>t;
    while(t--)
    {
        cin>>n; evens = odds = ans = 0;
        int ar[n];
        for(int i=0;i<n;i++) {cin>>ar[i]; if(ar[i]%2) odds++; else evens++; }
        sort(ar,ar+n);
        ans = evens*(evens-1)/2; ans += odds*(odds-1)/2; ans -= func(ar,n);
        cout<<ans<<"\n";
    }
    return 0;
}

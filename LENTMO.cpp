#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,k,x; cin>>T;
    while(T--)
    {
        cin>>n; ll ar[n];
        for(int i=0;i<n;i++) cin>>ar[i]; cin>>k>>x;
        ll s1 = accumulate(ar, ar+n, (ll)0);
        if(x == 0) {cout<<s1<<"\n"; continue;}
        ll xr[n]; for(int i=0;i<n;i++) xr[i] = ar[i] ^ x;
        ll s2 = accumulate(xr, xr+n, (ll)0);
        if(k == n) {cout<<max(s1, s2)<<"\n"; continue;}
        ll s = 0; int c = 0; ll mini = abs(ar[0] - xr[0]);
        for(int i=0;i<n;i++)
        {
            if(xr[i] > ar[i]) c++;
            s += max(ar[i], xr[i]);
            mini = min(mini, abs(ar[i] - xr[i]));
        }
        if(k & 1 || !(c & 1)) cout<<s<<"\n";
        else cout<<(s-mini)<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,ans; ll n,m; cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(m < n-1 || m > n*(n+1)/2) {cout<<"-1\n"; continue;}
        if(m == 0) {cout<<"0\n"; continue;}
        if(m == 1) {cout<<"1\n"; continue;}
        m -= (n+1); if(m <= 0) {cout<<"2\n"; continue;}
        m -= (n-1); if(m <= 0) {cout<<"3\n"; continue;}
        ans = 3;
        if(n & 1 == 0)
        {
            n = n >> 1;
            ans += m / n;
            if(m % n) ans++;
        }
        else
        {
            ans += 2*(m/n);
            m -= n*(m/n);
            if(m > 0 && m <= n/2) ans++;
            else if(m > 0) ans += 2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

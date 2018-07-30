#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        if(n==1)
        {
            if(ar[0]==1) {cout<<"YES\n"; continue;}
            else cout<<"NO\n"; continue;
        }
        int ans = ar[0];
        for(int i=1;i<n;i++)
        {
            ans = gcd(ans, ar[i]);
        }
        if(ans==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

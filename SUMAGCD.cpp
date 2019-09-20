#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {if(b == 0) return a; return gcd(b, a%b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,a; cin>>T;
    while(T--)
    {
        cin>>n; set<int> s;
        for(int i=0;i<n;i++) {cin>>a; s.insert(a);}
        n = s.size(); vector<int> ar(s.begin(), s.end());
        if(n == 1) {cout<<(2*ar[0])<<"\n"; continue;}
        int pre[n],post[n];
        pre[0] = ar[0]; for(int i=1;i<n;i++) pre[i] = gcd(pre[i-1], ar[i]);
        post[n-1] = ar[n-1]; for(int i=n-2;i>=0;i--) post[i] = gcd(post[i+1], ar[i]);
        int ans = max(ar[0] + post[1], ar[n-1] + pre[n-2]);
        for(int i=1;i<n-1;i++) ans = max(ans, ar[i] + gcd(pre[i-1], post[i+1]));
        cout<<ans<<"\n";
    }
    return 0;
}

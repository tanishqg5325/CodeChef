#include <bits/stdc++.h>
using namespace std;

int countu(int n)
{
    // maxm value of ans = 29
    int ans=0;
    while(n)
    {
        if(n%2) ans++;
        n /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,a,b,c,ans,c1,c2;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c; ans=0; c1 = countu(a); c2 = countu(b);
        for(int i=1;i<c;i++) if(countu(i) == c1 && countu(c-i) == c2) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n == 1) return 0;
    for(int i=2;i*i<=n;i++) if(n%i == 0) return 0;
    return 1;
}

bool isSemiPrime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            if(i*i != n && isPrime(n/i)) return 1;
            return 0;
        }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n; bool flag;
    bool sp[201]{};
    for(int i=1;i<=200;i++) sp[i] = isSemiPrime(i);
    cin>>t;
    while(t--)
    {
        cin>>n; flag = 0;
        for(int i=6;i<=n/2;i++) if(sp[i] && sp[n-i]) { flag =1; break; }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

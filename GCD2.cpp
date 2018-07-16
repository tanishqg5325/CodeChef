#include <bits/stdc++.h>
#include <string>
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
    int t,a,n,rem; string b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a==0) {cout<<b<<endl; continue;}
        n = b.size(); rem=0;
        for(int i=0;i<n;i++)
            rem = (rem*10 + b[i]-'0')%a;
        cout<<gcd(a,rem)<<"\n";
    }
    return 0;
}

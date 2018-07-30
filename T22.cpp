#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    for(int i=2;i*i<=num;i++)
        if(num%i==0)
            return false;
    return true;
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
        int ar[n],i;
        for(int i=0;i<n;i++) cin>>ar[i];
        sort(ar,ar+n);
        if(ar[0]!=1) {cout<<"-1\n"; continue;}
        for(i=1;i<n;i++)
            if(ar[i]!=1 && isPrime(ar[i]))
                break;
        if(i==n) cout<<"-1\n";
        else cout<<ar[i]<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int ans(int n)
{
    if(n==1) return 2;
    bool ar[35];
    int a = n,k=0,ones=0,i;
    while(a)
    {
        ar[k++] = a%2;
        if(a%2) ones++;
        a /= 2;
    }
    if(ones == 2) return 0;
    if(ones == 1) return 1;
    if(ar[k-1] && ar[k-2])  return min(n-(2<<(k-2))-(2<<(k-3)), (2<<(k-1))+1-n);
    for(i=k-3;i>=0;i--) if(ar[i]) break;
    return min(n-(2<<(k-2))-(2<<(i-1)), (2<<(k-2))+(2<<i)-n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ans(n)<<"\n";
    }
    return 0;
}

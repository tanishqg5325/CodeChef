#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,c,ans1=0,ans2;
    cin>>n;
    for(int i=0;i<n;i++) cin>>c, ans1+=c;
    ans2 = n*(n+1)/2;
    if(ans1==ans2) cout<<"YES";
    else cout<<"NO";
    return 0;
}

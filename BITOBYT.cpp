#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; ll a,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n--;
        a = n/26;
        a = (((ll)(1))<<a);
        n %= 26;
        if(n<2) cout<<a<<" 0 0\n";
        else if(n<10) cout<<"0 "<<a<<" 0\n";
        else cout<<"0 0 "<<a<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,x,s,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>s;
        while(s--)
        {
            cin>>a>>b;
            if(a == x) x=b;
            else if(b == x) x=a;
        }
        cout<<x<<"\n";
    }
    return 0;
}

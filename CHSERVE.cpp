#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,p1,p2,k;
    cin>>t;
    while(t--)
    {
        cin>>p1>>p2>>k;
        p1 = (p1+p2)%(2*k);
        if(p1<k) cout<<"CHEF\n";
        else cout<<"COOK\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,s,e;
    cin>>n>>c;
    if(n == 1) {cout<<"3 1"<<endl; return 0;}
    int ans = 0,i;
    for(i=400;i<n;i+=400)
    {
        cout<<"1 "<<i<<endl;
        cin>>ans;
        if(ans == 1) break;
    }
    s = i - 399; e = min(i,n);
    if(ans) cout<<"2"<<endl;
    ans = 0;
    for(i = s;i<e;i++)
    {
        cout<<"1 "<<i<<endl;
        cin>>ans;
        if(ans == 1) break;
    }
    if(ans) cout<<"3 "<<i<<endl;
    else cout<<"3 "<<e<<endl;
    return 0;
}

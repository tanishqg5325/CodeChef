#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n /= 2;
        cout<<1<<" "<<1;
        for(int i=0;i<n;i++) cout<<0;
        cout<<"\n";
    }
    return 0;
}

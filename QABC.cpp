#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        if(n == 1)
        {
            if(a[0] == b[0]) cout<<"TAK\n";
            else cout<<"NIE\n";
            continue;
        }
        bool flag=0;
        for(int i=0;i<n-2;i++)
        {
            if(a[i]>b[i]) {cout<<"NIE\n"; flag=1; break;}
            if(a[i] == b[i]) continue;
            int diff = b[i]-a[i];
            a[i] += diff; a[i+1] += (2*diff); a[i+2] += (3*diff);
        }
        if(flag) continue;
        if(a[n-2] == b[n-2] && a[n-1] == b[n-1]) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
    return 0;
}

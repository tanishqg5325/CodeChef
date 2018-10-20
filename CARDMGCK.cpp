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
        cin>>n; int ar[n]; for(int i=0;i<n;i++) cin>>ar[i];
        int temp=0,pos = -1;
        for(int i=1;i<n;i++)
        {
            if(ar[i] >= ar[i-1]) continue;
            else {temp++; pos = i;}
        }
        if(temp == 0) {cout<<"YES\n"; continue;}
        if(temp > 1) {cout<<"NO\n"; continue; }
        if(ar[0] >= ar[n-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

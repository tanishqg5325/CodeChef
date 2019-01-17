#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n; int ar[n]; int flag = 0; cin>>ar[0]; for(int i=1;i<n;i++) {cin>>ar[i]; if(ar[i] != ar[0]) flag = i;}
        if(flag == 0)
        {
            if(ar[0] == 0) cout<<n<<"\n";
            else if(ar[0] == n-1) cout<<"0\n";
            else cout<<"-1\n";
            continue;
        }
        bool flag2 = 1; for(int i=1;i<n;i++) if(ar[i] != ar[0] && ar[i] != ar[flag]) flag2=0;
        if(flag2 == 0) {cout<<"-1\n"; continue;}
        int n1 = min(ar[0],ar[flag]),n2 = max(ar[flag],ar[0]);
        if(n2-n1 != 1) {cout<<"-1\n"; continue;}
        int pass = 0;
        for(int i=0;i<n;i++) if(ar[i] == n1) pass++;
        if(pass != n2) {cout<<"-1\n"; continue;}
        cout<<n-pass<<"\n";
    }
    return 0;
}

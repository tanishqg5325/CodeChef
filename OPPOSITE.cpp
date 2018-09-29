#include <bits/stdc++.h>
using namespace std;

int n;

int opp(int i)
{
    return i+n/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        if(n%2) {cout<<"NO\n"; continue;}
        bool flag=1;
        for(int i=0;i<n/2;i++)
        {
            if(ar[i]== -1 && ar[opp(i)] == -1) ar[i]=ar[opp(i)]=1;
            else if(ar[i]==-1) ar[i]=ar[opp(i)];
            else if(ar[opp(i)]==-1) ar[opp(i)] =ar[i];
            else if(ar[i] != ar[opp(i)]) {flag=0; break;}
        }
        if(!flag) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++) cout<<ar[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; cin>>T;
    while(T--)
    {
        cin>>n; int a[n],d[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>d[i];
        vector<int> survivors;
        if(a[1] + a[n-1] < d[0]) survivors.pb(d[0]);
        if(a[n-2] + a[0] < d[n-1]) survivors.pb(d[n-1]);
        for(int i=1;i<n-1;i++)
            if(a[i-1] + a[i+1] < d[i]) survivors.pb(d[i]);
        if(survivors.empty()) cout<<"-1\n";
        else
        {
            sort(survivors.begin(), survivors.end());
            cout<<survivors.back()<<"\n";
        }
    }
    return 0;
}

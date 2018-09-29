#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.first <= p2.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        pair<int,int> p[n];
        for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
        sort(p,p+n); pair<int,int> a; a.second=0;
        while(m--)
        {
            cin>>a.first;
            if(a.first<=p[0].first) {cout<<p[0].first-a.first<<"\n"; continue;}
            if(a.first>=p[n-1].second) {cout<<"-1\n"; continue;}
            pair<int,int> *low = lower_bound(p, p+n, a, compare);
            int temp = low - p - 1;
            if(a.first<p[temp].second) cout<<0<<"\n";
            else cout<<p[temp+1].first-a.first<<"\n";
        }
    }
    return 0;
}

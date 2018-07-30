#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
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
        ll ar1[n]; unordered_map<ll,ll> map1;
        for(int i=0;i<n;i++) cin>>ar1[i];
        sort(ar1,ar1+n);
        ll ar[n]; int k=0;
        for(int i=0;i<n;i++)
        {
            while(i+1<n && ar1[i]==ar1[i+1]) i++;
            ar[k++]=ar1[i];
        }
        n=k;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                ll tmp = ar[i]*ar[i] + ar[j]*ar[j];
                if(map1.find(tmp) == map1.end())
                    map1[tmp] = 1;
                else
                    map1[tmp] += 1;
            }
        ll count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ll tmp = ar[i]*ar[i]+ar[j];
                if(map1.find(tmp) != map1.end()) count += map1[tmp];
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}

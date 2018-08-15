#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,maxlength,maxi;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair<int,int> ar[n];
        for(int i=0;i<n;i++) {cin>>ar[i].first; ar[i].second = i;}
        sort(ar,ar+n);
        maxlength = 1;
        maxi = ar[0].second;
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi, ar[i].second);
            maxlength = max(maxlength, maxi - ar[i].second + 1);
        }
        cout<<maxlength<<"\n";
    }
    return 0;
}

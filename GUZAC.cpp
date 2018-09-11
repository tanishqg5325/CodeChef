#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; ll n,k,x,sum,mini,maxi,maxim;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x;
        ll p[k];
        cin>>p[0]; sum = mini = maxi = p[0];
        for(int i=1;i<k;i++) {cin>>p[i]; sum += p[i]; mini=min(mini,p[i]); maxi=max(maxi,p[i]);}
        maxim = mini + x;

        cout<<sum<<"\n";
    }
    return 0;
}

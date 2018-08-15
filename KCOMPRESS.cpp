#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int ar[n]; pair<int,int> p[n];
        for(int i=0;i<n;i++) { cin>>ar[i]; p[i].first=ar[i]; p[i].second = i;}
        sort(p,p+n); int sum,ans=0,pos,maxi;
        for(int k=0;k<=n;k++)
        {
            int b[n]{}; // initialized b to 0s
            for(int i=0;i<n;i++)
            {
                pos=p[i].second; maxi=0;
                for(int j=max(0,pos-k);j<=min(n-1,pos+k);j++)
                {
                    if(ar[j]==p[i].first && b[j]!=0) {b[pos]=b[j]; break;}
                    maxi = max(maxi,b[j]);
                }
                if(!b[pos]) b[pos] = maxi+1;
            }
            for(int i=0;i<n;i++) cout<<b[i]<<" "; cout<<"\n";
            sum=0;
            for(int i=0;i<n;i++) sum += b[i];
            if(sum<=s) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

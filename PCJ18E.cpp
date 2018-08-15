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
        cin>>n; int ar[n],temp[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            temp[i]=ar[i];
        }
        sort(temp,temp+n);
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(ar[i]==temp[index]) index++;
        }
        cout<<n-index<<"\n";
    }
    return 0;
}

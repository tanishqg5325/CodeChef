#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k,sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>k; sum=0;
        bool ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        for(int i=0;i<n;i++)
        {
            if(ar[i])
            {
                if(i%2==0)
                {
                    if(sum>=0) sum++;
                    else sum--;
                }
                else
                {
                    if(sum>=0) sum--;
                    else sum++;
                }
            }
        }
        if(abs(sum) >= k) cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}

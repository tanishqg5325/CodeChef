#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n; ll ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        ll days(0), tmp = ar[0], ind(1),k,i;
        while(true)
        {
            k = tmp;
            for(i=ind;i<ind+k && i<n;i++) tmp += ar[i];
            ind += k;
            days++;
            if(i == n) break;
        }
        cout<<days<<"\n";
    }
    return 0;
}

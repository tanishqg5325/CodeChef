#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct trian
{
    int x,y,z;
    trian(int a, int b, int c)
    {
        x = a; y = b; z = c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,p,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>q;
        int ar[n],ind; pair<int,int> pa[n]; int pos[n];
        for(int i=0;i<n;i++) {cin>>ar[i]; pa[i].first = ar[i]; pa[i].second = i+1;}
        sort(ar,ar+n); sort(pa,pa+n);
        for(int i=0;i<n;i++) pos[i] = pa[i].second;
        vector<trian> v;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double d = ar[i]*ar[i] + ar[j]*ar[j] - 2.0*p*ar[i]*ar[j]/q;
                if(d<0) continue;
                int a = floor(sqrt(d));
                if(a < ar[0]) continue;
                if(a >= ar[n-1]) ind = n-1;
                else ind = upper_bound(ar,ar+n,a)-ar-1;
                while(ind == i || ind == j) ind--;
                if(ind < 0) continue;
                if(ar[ind] <= ar[j] - ar[i]) continue;
                v.push_back(trian(ind,i,j));
            }
        }
        if(v.size() == 0) {cout<<"-1\n"; continue;}
        int k = v.size();
        trian tt = v[0];
        double min_angle = 1.0*(ar[tt.y] * ar[tt.y] + ar[tt.z] *ar[tt.z] - ar[tt.x] * ar[tt.x])/(2*ar[tt.y]*ar[tt.z]);
        for(int i=1;i<k;i++)
        {
            trian aa = v[i];
            double tmp = 1.0*(ar[aa.y] * ar[aa.y] + ar[aa.z] *ar[aa.z] - ar[aa.x] * ar[aa.x])/(2*ar[aa.y]*ar[aa.z]);
            if(tmp < min_angle) {min_angle = tmp; tt = aa;}
        }
        cout<<pos[tt.x]<<" "<<pos[tt.y]<<" "<<pos[tt.z]<<"\n";
     }
    return 0;
}

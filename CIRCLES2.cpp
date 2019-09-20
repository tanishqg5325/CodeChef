#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; double x1,y1,r1,x2,y2,r2,d,x,y; cin>>T;
    cout<<fixed<<setprecision(8);
    while(T--)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if(r1 <= r2 && d <= r2 - r1) {cout<<"NO\n"; continue;}
        cout<<"YES\n";
        x = (x1 * (r1 + d) - r1 * x2) / d;
        y = (y1 * (r1 + d) - r1 * y2) / d;
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}

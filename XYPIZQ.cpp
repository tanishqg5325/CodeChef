#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; ll n,t,x,y,z,num,den,g; cin>>T;
    while(T--)
    {
        cin>>n>>t>>x>>y>>z;
        den = 2*n+1;
        if(t == 1)
        {
            if(x<y && y<z) num = 2*n + 1 - z;
            else if(x < y && y > z) num = x;
            else if(x > y && z > y) num =  x;
            else num = 2*n + 1 - z;
        }
        else if(t == 2)
        {
            if(x<y && y<z) num = 2*n + 1 - 2*y;
            else if(x < y && y > z) num = 0;
            else if(x > y && z > y) num =  0;
            else num = 2*n + 1 - 2*y;
        }
        else if(t == 3)
        {
            if(x<y && y<z) num = 2*n + 1 - x;
            else if(x < y && y > z) num = x;
            else if(x > y && z > y) num =  x;
            else num = 2*n + 1 - x;
        }
        else
        {
            if(x<y && y<z) num = 2*n + 1 - 2*y;
            else if(x < y && y > z) num = 0;
            else if(x > y && z > y) num =  0;
            else num = 2*n + 1 - 2*y;
        }
        g = __gcd(num,den);
        num /= g; den /= g;
        cout<<num<<" "<<den<<"\n";
    }
    return 0;
}

#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

long long volume(ll a, ll b, ll c)
{
    return a*b*c;
}

int main()
{
    int t;
    ll vol,a,b,c,x;
    double temp;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        x=1;
        vol = volume(1,a-1,b-1);
        c = min(a,b);
        temp = (a+b-sqrt(a*a + b*b - a*b))/3;
        ll t1 = (ll)floor(temp);
        ll t2 = (ll)ceil(temp);
        if(t1>=1 && t1<=(c-1))
        {
            if(volume(t1,a-t1,b-t1)>vol)
            {
                vol = volume(t1,a-t1,b-t1);
                x = t1;
            }
        }
        if(t2>=1 && t2<=(c-1))
        {
            if(volume(t2,a-t2,b-t2)>vol)
            {
                vol = volume(t2,a-t2,b-t2);
                x = t2;
            }
        }
        if(volume(c-1,a-c+1,b-c+1)>vol)
        {
            vol = volume(c-1,a-c+1,b-c+1);
            x = c-1;
        }
        cout<<x<<" "<<vol<<endl;
    }
    return 0;
}

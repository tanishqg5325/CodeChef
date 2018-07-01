#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    ll t_,r,R,p,a,t,n_d_r;
    bool x;
    double e_t,f_t,theta;
    cin>>t_;
    cout<<fixed;
    cout<<setprecision(5);
    while(t_--)
    {
        cin>>R>>r>>p>>a>>t;
        a = a%360;
        if(p!=0)
        {
            n_d_r = (ll)floor(p*t*1.0/(4*R));
            e_t = t - n_d_r*4.0*R/p;
            f_t = 2.0*(R-r)/p;
            if(e_t < f_t) x=0; else x=1;
            if(x==0) theta = (2*a*n_d_r)%360;
            else{theta = (a*(2*n_d_r+1))%360; e_t -= f_t;}
            if(x==0) theta += (180.0*p*e_t/(R-r));
            else theta -= (180.0*p*e_t/(R+r));
            theta += 360.0;
            theta -= 360.0*floor(theta/360.0);
        }
        else
        {
            x=0;
            theta=0;
        }
        cout<<x<<" "<<theta<<endl;
    }
    return 0;
}

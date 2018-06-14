#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double dist(long long p[3], double q[3])
{
    double a[3]={p[1]*q[2]-p[2]*q[1], p[2]*q[0]-p[0]*q[2], p[0]*q[1]-p[1]*q[0]};
    double b[3]={p[0]-q[0], p[1]-q[1], p[2]-q[2]};
    double temp1=0, temp2=0;
    for(int i=0;i<3;i++){temp1+=(a[i]*a[i]); temp2+=(b[i]*b[i]);}
    return sqrt(temp1/temp2);
}

int main()
{
    long long t,p[3],q[3],d[3],c[3],r;
    double time,speed,temp[3],dis;
    cin>>t;
    cout<<fixed;
    cout<<setprecision(8);
    while(t--)
    {
        for(int i=0;i<3;i++) cin>>p[i];
        for(int i=0;i<3;i++) cin>>q[i];
        for(int i=0;i<3;i++) cin>>d[i];
        for(int i=0;i<3;i++) cin>>c[i];
        cin>>r;
        for(int i=0;i<3;i++){p[i]-=c[i]; q[i]-=c[i]; c[i]=0;}
        double a_time=0, b_time=10;
        while(true)
        {
            for(int i=0;i<3;i++) temp[i]=q[i]+(b_time*d[i]);
            if(dist(p,temp)>r) break;
            b_time*=10;
        }
        while((b_time-a_time)>pow(10,-8))
        {
            time=(a_time+b_time)/2;
            for(int i=0;i<3;i++) temp[i]=q[i]+(time*d[i]);
            dis = dist(p,temp);
            if(dis==r) break;
            else if(dis<r) a_time=time;
            else b_time=time;
        }
        cout<<time<<endl;
    }
    return 0;
}

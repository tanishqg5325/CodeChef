#include <iostream>
#include <math.h>

using namespace std;

struct point
{
    int x;
    int y;
};

float dist(point p, point q)
{
    return sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2));
}

int main()
{
    int t,r;
    float ar[3];
    point person[3];
    cin>>t;
    while(t--)
    {
        cin>>r;
        for(int i=0;i<3;i++)
            cin>>person[i].x>>person[i].y;
        ar[0]=dist(person[0],person[1]);
        ar[1]=dist(person[1],person[2]);
        ar[2]=dist(person[2],person[0]);
        if(((ar[0]>r)+(ar[1]>r)+(ar[2]>r))<=1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}


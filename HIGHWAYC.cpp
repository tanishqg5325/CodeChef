#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t,n;
    double s,y,ans,l=0.000001f,time;
    cin>>t;
    while(t--)
    {
        cin>>n>>s>>y;
        double p[n];
        ans=0;
        int d[n],v[n],c[n];
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
            if(d[i]==0)
                d[i]=-1;
        }
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        for(int i=0;i<n;i++)
        {
            if((p[i]*d[i]-l-c[i])>0)
                time=y/s;
            else if((p[i]*d[i]+l)>=(-v[i]*y/s))
                time=(y/s)+(c[i]+l-p[i]*d[i])/v[i];
            else
                time=y/s;
            ans+=time;
            for(int j=i+1;j<n;j++)
                p[j]+=(v[j]*d[j]*time);
        }
        cout<<ans<<endl;
    }
    return 0;
}

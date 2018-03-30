#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int p1[10000],p2[10000],l,w,pos=0,n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p1[i]>>p2[i];
    l=abs(p1[0]-p2[0]);
    for(int i=1;i<n;i++)
    {
        p1[i]+=p1[i-1];
        p2[i]+=p2[i-1];
        if(l<abs(p1[i]-p2[i]))
        {
            l=abs(p1[i]-p2[i]);
            pos=i;
        }
    }
    if(p1[pos]>p2[pos])
        w=1;
    else
        w=2;
    cout<<w<<" "<<l;
    return 0;
}

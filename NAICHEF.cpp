#include <iostream>
using namespace std;

int main()
{
    int t,n,a,b;
    double ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        int num;
        int count1=0,count2=0;
        for(int i=0;i<n;i++) {cin>>num; if(num==a) count1++; if(num==b) count2++;}
        ans=(double)(count1*count2)/(n*n);
        cout<<ans<<endl;
    }
    return 0;
}

#include <iostream>

int abs(int a)
{
    if(a>=0)
        return a;
    return -a;
}

using namespace std;

int main()
{
    int t,a,b,c,ans,temp;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if((a+c)%2==0)
            ans=abs((a+c)/2-b);
        else
            ans=min(abs((a+c-1)/2-b),abs((a+c+1)/2-b))+1;
        cout<<ans<<endl;
    }
    return 0;
}

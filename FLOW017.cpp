#include <iostream>

using namespace std;

int main()
{
    int t,a,b,c,l,s;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        l=max(a,b);
        s=min(a,b);
        if(c>l)
            s=l;
        else if(c>s)
            s=c;
        cout<<s<<endl;
    }
    return 0;
}


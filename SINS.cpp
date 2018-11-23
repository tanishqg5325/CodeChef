#include <iostream>

using namespace std;

int main()
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        while(true)
        {
            if(x==y || x==0 || y==0)
                break;
            else if(x>y)
            {
                if(x%y==0)
                    x=y;
                else
                    x=x%y;
            }
            else
            {
                if(y%x==0)
                    y=x;
                else
                    y=y%x;
            }
        }
        cout<<x+y<<endl;
    }
    return 0;
}

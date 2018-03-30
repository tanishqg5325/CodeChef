#include <iostream>

using namespace std;

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<max(a,b)<<" "<<a+b<<endl;
    }
    return 0;
}
